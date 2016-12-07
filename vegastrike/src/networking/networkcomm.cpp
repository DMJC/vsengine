#include <assert.h>
#include "config.h"
#ifdef NETCOMM_JVOIP
#include <jvoiplib/jvoipsession.h>
#include <jvoiplib/jvoiprtptransmission.h>
#endif /* NETCOMM_JVOIP */
#ifdef CRYPTO
#include <crypto++/filters.h>
#include <crypto++/hex.h>
#include <crypto++/randpool.h>
#include <crypto++/files.h>

#include <crypto++/rsa.h>
#include <crypto++/des.h>
#include <crypto++/sha.h>
#endif /* CRYPTO */

#include "vs_globals.h"
#include "cmd/unit_generic.h"
#include "networking/networkcomm.h"
#include "vsfilesystem.h"
#include "universe_util.h"
#include "networking/lowlevel/vsnet_dloadmgr.h"
#ifdef NETCOMM_WEBCAM
#include "networking/webcam_support.h"
#endif /* NETCOMM_NOWEBCAM */
#include "networking/lowlevel/packet.h"
#include "xml_support.h"

using namespace VSFileSystem;
#ifdef CRYPTO
using namespace CryptoPP;
#endif

bool use_pa;
bool use_secured;

#define VOIP_PORT 5000
extern bool cleanexit;
#ifdef NETCOMM_JVOIP
void CheckVOIPError( int val )
{
    if (val >= 0)
        return;
    string error = JVOIPGetErrorString( val );
    cerr<<"!!! JVOIP ERROR : "<<error<<endl;
    cleanexit = true;
    VSExit( 1 );
}
#endif /* NETCOMM_JVOIP */
#ifdef NETCOMM_PORTAUDIO
void CheckPAError( PaError err, const char *fun )
{
    if (use_pa) {
        if (err == paNoError)
            return;
        cerr<<"!!! PORTAUDIO ERROR in "<<fun<<": "<<Pa_GetErrorText( err )<<endl;
        if (err == paHostError)
            cerr<<"!!! PA HOST ERROR : "<<Pa_GetHostError()<<" - "<<Pa_GetErrorText( Pa_GetHostError() )<<endl;
        cleanexit = true;
        VSExit( 1 );
    }
}

void Pa_DisplayInfo( PaDeviceID id )
{
    const PaDeviceInfo *info = Pa_GetDeviceInfo( id );

    cout<<"PORTAUDIO Device "<<id<<"---------------"<<endl;
    cout<<"\tName : "<<info->name<<endl;
    cout<<"\tStructure version : "<<info->structVersion<<endl;
    cout<<"\tmaxInputChannels : "<<info->maxInputChannels<<endl;
    cout<<"\tmaxOutputChannels : "<<info->maxOutputChannels<<endl;
    cout<<"\tnativeSampleFormats : ";
    switch (info->nativeSampleFormats)
    {
    case (paFloat32):
        cout<<"paFloat32"<<endl;
        break;
    case (paInt16):
        cout<<"paInt16"<<endl;
        break;
    case (paInt32):
        cout<<"paInt32"<<endl;
        break;
    case (paInt24):
        cout<<"paInt24"<<endl;
        break;
    case (paPackedInt24):
        cout<<"paPackedInt24"<<endl;
        break;
    case (paInt8):
        cout<<"paInt8"<<endl;
        break;
    case (paUInt8):
        cout<<"paUInt8"<<endl;
        break;
    case (paCustomFormat):
        cout<<"paCustomFormat"<<endl;
        break;
    }
    cout<<"\tnumSampleRates : "<<info->numSampleRates<<endl;
    for (int i = 0; i < info->numSampleRates; i++)
        cout<<"\t\tRate "<<i<<" = "<<info->sampleRates[i];
}

int Pa_RecordCallback( void *inputBuffer,
                       void *outputBuffer,
                       unsigned long framesPerBuffer,
                       PaTimestamp outTime,
                       void *userdata )
{
    NetworkCommunication *netcomm = (NetworkCommunication*) userdata;
    unsigned short *in = (unsigned short*) inputBuffer;
    //Only act if PA CPU Load is low enough and if we have data in the input buffer
    if (Pa_GetCPULoad( netcomm->instream ) < MAX_PA_CPU_LOAD && in) {
        netcomm->audio_inlength = sizeof (unsigned short)*framesPerBuffer;
        cerr<<"Input BUFFER SIZE = "<<netcomm->audio_inlength<<endl;
        memset( netcomm->audio_inbuffer, 0, MAXBUFFER );
        //Maybe put ushort by ushort in the buffer and prepare them for network (htons)
        memcpy( netcomm->audio_inbuffer, in, netcomm->audio_inlength );
    }
    return 0;
}

int Pa_PlayCallback( void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, PaTimestamp outTime, void *userdata )
{
    NetworkCommunication *netcomm = (NetworkCommunication*) userdata;
    unsigned short *out = (unsigned short*) outputBuffer;
    //Copy the last received sound buffer if not yet played (would be NULL) and if PA CPU load is low enough
    if (Pa_GetCPULoad( netcomm->outstream ) < MAX_PA_CPU_LOAD && netcomm->audio_outbuffer)
        memcpy( out, netcomm->audio_outbuffer, sizeof (unsigned short)*framesPerBuffer );
    return 0;
}

#endif /* NETCOMM_PORTAUDIO */

void NetworkCommunication::private_init()
{
    this->active = false;
    this->max_messages = 25;
    this->method       = ClientBroadcast;
    use_pa = XMLSupport::parse_bool( vs_config->getVariable( "network", "use_portaudio", "false" ) );
    use_secured        = 0;

#ifdef NETCOMM_JVOIP
    this->session      = NULL;
    this->params       = NULL;
    this->rtpparams    = NULL;
#endif /* NETCOMM_JVOIP */

#ifdef NETCOMM_PORTAUDIO
    this->indev   = paNoDevice;
    this->outdev  = paNoDevice;
    this->devinfo = NULL;
#endif /* NETCOMM_PORTAUDIO */

#ifdef NETCOMM_WEBCAM
    this->Webcam = NULL;
#endif
}

NetworkCommunication::NetworkCommunication()
{
    private_init();
}

NetworkCommunication::NetworkCommunication( float minfreq, float maxfreq, bool video, bool secured, string cryptomethod )
{
    min_freq = minfreq;
    max_freq = maxfreq;
    private_init();
#ifdef NETCOMM_WEBCAM
    if (video) {
        //Init the webcam part
        Webcam = new WebcamSupport();
        if (Webcam->Init() == -1) {
            delete Webcam;
            this->Webcam = NULL;
            cerr<<"!!! NO WEBCAM SUPPORT !!!"<<endl;
        }
        _downloader.reset( new VsnetDownload::Client::Manager( _sock_set ) );
        _sock_set.addDownloadManager( _downloader );
        _downloadServer.reset( new VsnetDownload::Server::Manager( _sock_set ) );
        _sock_set.addDownloadManager( _downloadServer );
    }
#endif /* NETCOMM_NOWEBCAM */

#ifdef NETCOMM_PORTAUDIO
    //Initialize PortAudio lib
    if (use_pa)
        CheckPAError( Pa_Initialize(), "Pa_Initialize" );
    //Testing purpose : list devices and display info about them
    if (use_pa) {
        int nbdev = Pa_CountDevices();
        for (int i = 0; i < nbdev; i++)
            Pa_DisplayInfo( i );
    }
    //Get the default devices for input and output streams
    if (use_pa) {
        this->indev  = Pa_GetDefaultInputDeviceID();
        this->outdev = Pa_GetDefaultOutputDeviceID();
    }
    this->sample_rate    = 11025;
    this->audio_inlength = 0;
#endif /* NETCOMM_PORTAUDIO */

#ifdef CRYPTO
    crypto_method    = cryptomethod;
    pubKeyFilename   = VSFileSystem::datadir+"vsnet_public_"+crypto_method+".key";
    privKeyFilename  = VSFileSystem::datadir+"vsnet_private_"+crypto_method+".key";
    seed = vs_config->getVariable( "network", "encryption_seed", "I love VegaStrike" );     //;)
    //Key length is only used when we need to generate a key
    this->key_length = XMLSupport::parse_int( vs_config->getVariable( "network", "encryption_keylength", "40" ) );
    bool    create_keys = false;
    VSFile  f1, f2;
    VSError err1 = f1.OpenReadOnly( pubKeyFilename, VSFileSystem::UnknownFile );
    VSError err2 = f2.OpenReadOnly( privKeyFilename, VSFileSystem::UnknownFile );
    if (err1 > Ok || err2 > Ok) {
        //There is a file we cannot open so we create keys
        create_keys = true;
    } else {
        //Read the keys in their buffers
        this->pubkey  = f1.ReadFull();
        this->privkey = f2.ReadFull();
    }
    if (err1 <= Ok)
        f1.Close();
    if (err2 <= Ok)
        f2.Close();
    if (create_keys)
        this->GenerateKey();
#endif
}

char NetworkCommunication::HasWebcam()
{
#ifdef NETCOMM_WEBCAM
    if (this->Webcam)
        return 1;
    return 0;

#else
    return 0;
#endif
}

char NetworkCommunication::HasPortaudio()
{
#ifdef NETCOMM_PORTAUDIO
    return 1;

#else
    return 0;
#endif
}

NetworkCommunication::NetworkCommunication( int nb )
{
    private_init();
    assert( nb < 65536 );
    this->max_messages = nb;
}

void NetworkCommunication::AddToSession( ClientPtr clt )
{
    this->commClients.push_back( clt );
    //If the client has a webcam enabled and we don't have one selected yet
    //FIND A FIX FOR THAT TEST
    if (*(this->webcamClient) && clt->webcam) {
        CltPtrIterator cltit = commClients.end();
        assert( (*cltit) == clt );
        this->webcamClient = cltit;
    }
#ifdef NETCOMM_JVOIP
    CheckVOIPError( this->session->AddDestination( ntohl( clt->cltadr.inaddr() ), VOIP_PORT ) );
#endif /* NETCOMM_JVOIP */
}

void NetworkCommunication::RemoveFromSession( ClientPtr clt )
{
    this->commClients.remove( clt );
#ifdef NETCOMM_JVOIP
    CheckVOIPError( this->session->AddDestination( ntohl( clt->cltadr.inaddr() ), VOIP_PORT ) );
#endif /* NETCOMM_JVOIP */
}

/*
 **************************************************************************************
 **** Send text message                                                             ***
 **** Broadcast string function param as a text message to the current frequency    ***
 **************************************************************************************
 */
void NetworkCommunication::SendMessage( SOCKETALT &send_sock, ObjSerial serial, string message )
{
    Packet p;
    string encrypted;
    //If max log size is reached we remove the oldest message
    if (this->message_history.size() == this->max_messages)
        this->message_history.pop_front();
    this->message_history.push_back( message );
    //Send the text message according to the chosen method
    if (method == ServerUnicast) {
        //SEND STRNIG PARAMETER TO SERVER SO THAT HE BROADCASTS IT TO CONCERNED PLAYERS
#ifdef CRYPTO
        if (this->secured && use_secured) {
            encrypted = this->EncryptBuffer( message.c_str(), message.length() );
            p.send( CMD_TXTMESSAGE, serial, encrypted.c_str(), message.length(), SENDRELIABLE, NULL, send_sock,
                   __FILE__, PSEUDO__LINE__( 244 ) );
        } else
#endif
        {
            p.send( CMD_SECMESSAGE, serial, message.c_str(), message.length(), SENDRELIABLE, NULL, send_sock,
                   __FILE__, PSEUDO__LINE__( 244 ) );
        }
    } else if (method == ClientBroadcast) {
        //SEND STRING PARAMETER TO EACH PLAYER COMMUNICATING ON THAT FREQUENCY
        CltPtrIterator it;
        for (it = commClients.begin(); it != commClients.end(); it++) {
#ifdef CRYPTO
            if (this->secured && use_secured) {
                encrypted = this->EncryptBuffer( message.c_str(), message.length() );
                p.send( CMD_TXTMESSAGE, serial, encrypted.c_str(), message.length(), SENDRELIABLE, NULL, (*it)->tcp_sock,
                       __FILE__, PSEUDO__LINE__( 244 ) );
            } else
#endif
            {
                p.send( CMD_SECMESSAGE, serial, message.c_str(), message.length(), SENDRELIABLE, NULL, (*it)->tcp_sock,
                       __FILE__, PSEUDO__LINE__( 244 ) );
            }
        }
    }
}

/*
 **************************************************************************************
 **** Send sound sample in PortAudio mode                                           ***
 **** Send audio_inbuffer over the network according to the chosen method           ***
 **************************************************************************************
 */
void NetworkCommunication::SendSound( SOCKETALT &sock, ObjSerial serial )
{
#ifdef USE_PORTAUDIO
    string encrypted;
    if (use_pa) {
        Packet p;
        if (method == ServerUnicast) {
            //SEND INPUT AUDIO BUFFER TO SERVER SO THAT HE BROADCASTS IT TO CONCERNED PLAYERS
            Packet p;
            //We don't need that to be reliable in UDP mode
#ifdef CRYPTO
            if (this->secured && use_secured) {
                encrypted = this->EncryptBufer( this->audio_inbuffer, this->audio_inlength );
                p.send( CMD_SOUNDSAMPLE, serial, encrypted.c_str(), encrypted.length(), SENDANDFORGET, NULL, sock,
                       __FILE__, PSEUDO__LINE__( 244 ) );
            } else
#endif
            {
                p.send( CMD_SECSNDSAMPLE, serial, this->audio_inbuffer, this->audio_inlength, SENDANDFORGET, NULL, sock,
                       __FILE__, PSEUDO__LINE__( 244 ) );
            }
        } else if (method == ClientBroadcast) {
            //SEND INPUT AUDIO BUFFER TO EACH PLAYER COMMUNICATING ON THAT FREQUENCY
            CltPtrIterator it;
            for (it = commClients.begin(); it != commClients.end(); it++) {
                if ( (*it)->portaudio ) {
#ifdef CRYPTO
                    if (this->secured && use_secured) {
                        encrypted = this->EncryptBufer( this->audio_inbuffer, this->audio_inlength );
                        p.send( CMD_SOUNDSAMPLE, serial, encrypted.c_str(),
                               encrypted.length(), SENDANDFORGET, NULL, (*it)->sock,
                               __FILE__, PSEUDO__LINE__( 244 ) );
                    } else
#endif
                    {
                        p.send( CMD_SECSNDSAMPLE, serial, this->audio_inbuffer, this->audio_inlength, SENDANDFORGET, NULL,
                               (*it)->sock,
                               __FILE__, PSEUDO__LINE__(
                                   244 ) );
                    }
                }
            }
        }
        memset( audio_inbuffer, 0, MAXBUFFER );
    }
#endif /* USE_PORTAUDIO */
//Do not do anything when using JVoIP lib
}

void NetworkCommunication::RecvSound( const char *sndbuffer, int length, bool encrypted )
{
#ifdef NETCOMM_PORTAUDIO
    if (use_pa) {
        string decrypted;
        assert( length < MAXBUFFER );
        memset( audio_outbuffer, 0, MAXBUFFER );
#ifdef CRYPTO
        if (encrypted) {
            decrypted = DecryptBuffer( sndbuffer, length );
            memcpy( audio_outbuffer, decrypted.c_str(), decrypted.length() );
        } else
#endif
        memcpy( audio_outbuffer, sndbuffer, length );
    }
#endif
}

void NetworkCommunication::RecvMessage( string message, bool encrypted )
{
    //If max log size is reached we remove the oldest message
    if (this->message_history.size() == this->max_messages)
        this->message_history.pop_front();
    string decrypted;
#ifdef CRYPTO
    if (encrypted) {
        decrypted = DecryptBuffer( message.c_str(), message.length() );
        message   = decrypted;
    }
#endif

    this->message_history.push_back( message );
    //Display message
    string color;
    if (secured)
        color = "#DD0000";
    else
        color = "#99CCFF";
    UniverseUtil::IOmessage( 0, "game", "all", color+message+"#000000" );
}

/*
 **************************************************************************************
 **** Send a webcam capture                                                         ***
 **** Send jpeg_buffer over the network according to the chosen method              ***
 **************************************************************************************
 */
/*
 *  void	NetworkCommunication::SendImage( SOCKETALT & send_sock)
 *  {
 *       string jpeg_str( "");
 * #ifdef NETCOMM_WEBCAM
 *       if( Webcam && Webcam->isReady())
 *       {
 *               //cerr<<"--- Trying to grab an image..."<<endl;
 *               //cerr<<"\t";
 *               jpeg_str = Webcam->CaptureImage();
 *               //cerr<<"--- grabbing finished"<<endl;
 *       }
 *       if( method==ServerUnicast)
 *       {
 *               // SEND GRABBED IMAGE TO SERVER SO THAT HE BROADCASTS IT TO CONCERNED PLAYERS
 *       }
 *       else if( method==ClientBroadcast)
 *       {
 *               // SEND GRABBED IMAGE TO EACH PLAYER COMMUNICATING ON THAT FREQUENCY
 *       }
 * #endif
 *  }
 */

int NetworkCommunication::InitSession( float frequency )
{
    //Init the VoIP session
#ifdef NETCOMM_JVOIP
    this->session   = new JVOIPSession;
    this->session->SetSampleInterval( 100 );

    this->params    = new JVOIPSessionParams;
    this->rtpparams = new JVOIPRTPTransmissionParams;

    CheckVOIPError( this->session->Create( *(this->params) ) );
#endif /* NETCOMM_JVOIP */

#ifdef NETCOMM_PORTAUDIO
    if (use_pa) {
        //Create the input stream with indev and 1 channel with paInt16 samples
        CheckPAError( Pa_OpenStream( &this->instream,
                                     this->indev, 1, paInt16, NULL,
                                     paNoDevice, 0, paInt16, NULL,
                                     this->sample_rate, 256, 0, paNoFlag,
                                     Pa_RecordCallback, (void*) this ), "Pa_OpenStream(instream)" );

        //Create the output stream with outdev and 1 channel with paInt16 samples
        CheckPAError( Pa_OpenStream( &this->outstream,
                                     paNoDevice, 0, paInt16, NULL,
                                     this->outdev, 1, paInt16, NULL,
                                     this->sample_rate, 256, 0, paNoFlag,
                                     Pa_PlayCallback, (void*) this ), "Pa_OpenStream(outstream)" );
        if (this->instream)
            CheckPAError( Pa_StartStream( this->instream ), "Pa_StartStream(instream)" );
        if (this->outstream)
            CheckPAError( Pa_StartStream( this->outstream ), "Pa_StartStream(outstream)" );
    }
#endif /* NETCOMM_PORTAUDIO */

#ifdef NETCOMM_WEBCAM
    if (Webcam)
        this->Webcam->StartCapture();
#endif /* NETCOMM_NOWEBCAM */

    this->active = true;
    this->freq   = frequency;
    return 0;
}

int NetworkCommunication::DestroySession()
{
    this->active = false;
#ifdef NETCOMM_PORTAUDIO
    if (use_pa) {
        CheckPAError( Pa_StopStream( this->instream ), "Pa_StopStream(instream)" );
        CheckPAError( Pa_StopStream( this->outstream ), "Pa_StopStream(outstream)" );

        CheckPAError( Pa_CloseStream( this->instream ), "Pa_CloseStream(instream)" );
        CheckPAError( Pa_CloseStream( this->outstream ), "Pa_CloseStream(outstream)" );
    }
#endif
#ifdef NETCOMM_JVOIP
    CheckVOIPError( this->session->Destroy() );
    if (this->session)
        delete this->session;
    if (this->params)
        delete this->params;
    if (this->rtpparams)
        delete this->rtpparams;
#endif /* NETCOMM_JVOIP */
#ifdef NETCOMM_WEBCAM
    if (this->Webcam)
        this->Webcam->EndCapture();
    if (bufitem) {
        delete bufitem;
        bufitem == NULL;
    }
#endif /* NETCOMM_NOWEBCAM */

    return 0;
}

NetworkCommunication::~NetworkCommunication()
{
#ifdef NETCOMM_JVOIP
    if (this->session)
        delete this->session;
    if (this->params)
        delete this->params;
    if (this->rtpparams)
        delete this->rtpparams;
#endif /* NETCOMM_JVOIP */
#ifdef NETCOMM_PORTAUDIO
    if (use_pa)
        CheckPAError( Pa_Terminate(), "Pa_Terminate" );
#endif /* NETCOMM_PORTAUDIO */
#ifdef NETCOMM_WEBCAM
    if (this->Webcam) {
        this->Webcam->Shutdown();
        delete this->Webcam;
        this->Webcam = NULL;
    }
    if (bufitem)
        delete bufitem;
#endif /* NETCOMM_NOWEBCAM */
#ifdef CRYPTO
#endif
}

char* NetworkCommunication::GetWebcamCapture()
{
#ifdef NETCOMM_WEBCAM
    if (Webcam != NULL)
        return Webcam->jpeg_buffer;
#endif
    return NULL;     //We have no choice :-/
}

char* NetworkCommunication::GetWebcamFromNetwork( int &length )
{
    char *wshot = NULL;
#ifdef NETCOMM_WEBCAM
    if ( (*webcamClient) && bufitem ) {
        if ( !bufitem->done() ) {
            return NULL;
        } else {
            //Re add the buf to get another webcam shot
            length = bufitem->getSize();
            wshot  = new char[bufitem->getSize()+1];
            memcpy( wshot, bufitem->getBuffer().get(), bufitem->getSize() );
            wshot[bufitem->getSize()] = 0;
            _downloader->addItem( bufitem );
        }
    }
#endif
    return wshot;
}

void NetworkCommunication::StopWebcamTransfer()
{
#ifdef NETCOMM_WEBCAM
    if (bufitem)
        //Abort current transfer
        //- remove from dloadmgr
        //- delete it
        bufitem = NULL;
#endif
}

void NetworkCommunication::StartWebcamTransfer()
{
#ifdef NETCOMM_WEBCAM
    //To select the first webcam to display and begin transfers
    this->SwitchWebcam();
#endif
}

void NetworkCommunication::SwitchWebcam()
{
#ifdef NETCOMM_WEBCAM
    bool found = false;
    CltPtrIterator it;
    if (bufitem)
        delete bufitem;
    //Go through listClients from current client to the end in order to find the next webcam client
    if ( (*this->webcamClient) )
        it = ++webcamClient;
    else
        it = commClients.begin();
    for (; it != commClients.end() && !found; it++)
        if ( (*it)->webcam )
            found = true;
    //If a client with webcam support was not found before the end we go through listClients from te beginning
    if (!found) {
        for (it = commClients.begin(), found = false; it != webcamClient && !found; it++)
            if ( (*it)->webcam )
                found = true;
        //If we found another client supporting webcam
        if (found)
            webcamClient = it;
    }
    if (found)
        //Should init transfer and buf with right values
        //1. Create a socket to the interested client
        //2. Init the bufitem
        //bufitem = new VsnetDownload::Client::Buffer(...);
        _downloader->addItem( bufitem );
#endif
}

void NetworkCommunication::SwitchSecured()
{
#ifdef CRYPTO
    if (secured)
        secured = 0;
    else if (use_secured && crypt_key[0] != 0)
        secured = 1;
#else
    //If compiled without crypto++ support secured comms are not available
    secured = 0;
#endif
}

void NetworkCommunication::GenerateKey()
{
#ifdef CRYPTO
    if (crypto_method == "rsa") {
        use_secured = true;
        RandomPool randPool;
        randPool.Put( (byte*) this->seed.c_str(), this->seed.length() );

        RSAES_OAEP_SHA_Decryptor priv( randPool, this->key_length );
        HexEncoder privFile( new FileSink( privKeyFilename.c_str() ) );
        HexEncoder privstr( new StringSink( privkey ) );
        priv.DEREncode( privFile );
        privFile.MessageEnd();

        RSAES_OAEP_SHA_Encryptor pub( priv );
        HexEncoder pubFile( new FileSink( pubKeyFilename.c_str() ) );
        HexEncoder pubstr( new StringSink( pubkey ) );
        pub.DEREncode( pubFile );
        pubFile.MessageEnd();
    } else if (crypto_method == "3des") {
        use_secured = true;
        /* initialize a DES-EDE3 encryption filter with a 192 bit (24 bytes) key */
        static DES_EDE3_Encryption des_encryptor( (byte*) privkey.c_str(), 24 );
        static DES_EDE3_Decryption des_decryptor( (byte*) privkey.c_str(), 24 );
    } else {
        use_secured = false;
    }
#endif
}

string NetworkCommunication::EncryptBuffer( const char *buffer, unsigned int length )
{
    string result;
#ifdef CRYPTO
    if (crypto_method == "rsa") {
        StringSource pubstr( pubkey, true, new HexDecoder );
        RSAES_OAEP_SHA_Encryptor pub( pubstr );

        randPool.Put( (byte*) seed.c_str(), seed.length() );

        StringSource( buffer, true, new PK_EncryptorFilter( randPool, pub, new HexEncoder( new StringSink( result ) ) ) );
    } else if (crypto_method == "3des") {
        /* calculate how many blocks (each block is 8 bytes) the input consists of, add
         *  padding if needed */
        /*
         *  int nBlocks = length / 8;
         *  if (length % 8 != 0)
         *       nBlocks ++;
         *  // allocate the output buffer
         *  byte*	pResult = new byte[nBlocks * 8];
         *  byte	plainByte [8];
         *  // encrypt the blocks one by one
         *  for (int block_num = 0; block_num < nBlocks; block_num ++)
         *  {
         *       // build the 8 byte block plain text, add padding if needed
         *       for (int i = 0 ; i < 8; i++)
         *       {
         *               // this is a full block
         *               if (block_num * 8 + i < length)
         *               {
         *                       plainByte[i] = buffer[block_num * 8 + i];
         *               }
         *               // this is the last block that needs padding
         *               else
         *               {
         *                       plainByte[i]  = 0x00; // pad with a random byte
         *               }
         *       }
         *       // encrypt the 8 byte block and store in output buffer
         *  if (encrypting_mode)
         *       des_encryptor.ProcessBlock(plainByte, pResult + block_num * 8);
         *  else
         *       des_decryptor.ProcessBlock(plainByte, pResult + block_num * 8);
         *  }
         * *output_length= nBlocks * 8;
         *  return pResult;
         */
    } else {}
#endif /* CRYPTO */
    return result;
}

string NetworkCommunication::DecryptBuffer( const char *buffer, unsigned int length )
{
    string result;
#ifdef CRYPTO
    if (crypto_method == "rsa") {
        StringSource privstr( privkey, true, new HexDecoder );
        RSAES_OAEP_SHA_Decryptor priv( privstr );

#if CRYPTO == 50
        StringSource( buffer, true, new HexDecoder( new PK_DecryptorFilter( priv, new StringSink( result ) ) ) );
#else
        StringSource( buffer, true, new HexDecoder( new PK_DecryptorFilter( randPool, priv, new StringSink( result ) ) ) );
#endif
    } else if (crypto_method == "3des") {} else {}
#endif /* CRYPTO */
    return result;
}

