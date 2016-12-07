#include "cmd/unit_generic.h"
#include "networking/client.h"
#include "networking/acctserver.h"
#include "networking/lowlevel/packet.h"
#include "lin_time.h"
#include "networking/lowlevel/vsnet_serversocket.h"
#include "vsfilesystem.h"
#include "vs_globals.h"
#include "networking/lowlevel/netbuffer.h"
#include "networking/lowlevel/vsnet_debug.h"
#include "networking/fileutil.h"
#include "posh.h"
#include "options.h"

using namespace VSFileSystem;

VegaConfig *vs_config = NULL;
string acctdir;

void getZoneInfoBuffer( unsigned short zoneid, NetBuffer &netbuf )
{}

AccountServer::AccountServer() :
    _sock_set( true )
{
    cout<<endl<<POSH_GetArchString()<<endl;
    cout<<"AccountServer init"<<endl;
    //Network = new TCPNetUI;
    newaccounts = 0;
    UpdateTime();
    srand( (int) getNewTime() );
    serial_seed = (ObjSerial) ( rand()*( 500./( ( (double) (RAND_MAX) )+1 ) ) );
}

/*
 *************************************************************
 **** Authenticate a connected client                      ***
 *************************************************************
 */

AccountServer::~AccountServer()
{
    delete Network;
}

/*
 *************************************************************
 **** Display info on the server at startup                ***
 *************************************************************
 */

void AccountServer::startMsg()
{
    cout<<endl<<"Vegastrike Account Server version 0.0.1"<<endl;
    cout<<"Written by Stephane Vaxelaire"<<endl<<endl;
}

void AccountServer::start()
{
    string    strperiod;
    keeprun = 1;

    SOCKETALT comsock;

    startMsg();

    CONFIGFILE = new char[42];
    strcpy( CONFIGFILE, "accountserver.config" );
    cout<<"Loading config file...";
    VSFileSystem::InitPaths( CONFIGFILE );
    //vs_config = new VegaConfig( ACCTCONFIGFILE);
    cout<<" done."<<endl;
    InitTime();
    UpdateTime();
    acctdir   = VSFileSystem::datadir+vs_config->getVariable( "server", "accounts_dir", "/accounts/" );
    strperiod = vs_config->getVariable( "server", "saveperiod", "" );
    int period;
    if (strperiod == "")
        period = 7200;
    else
        period = atoi( strperiod.c_str() );
    savetime = getNewTime()+period;

    cout<<"Loading accounts data... ";
    LoadAccounts( "accounts.xml" );
    //Gets hashtable accounts elements and put them in vector Cltacct

    //Create and bind socket
    cout<<"Initializing network..."<<endl;
    unsigned short tmpport;
    if (vs_config->getVariable( "network", "accountsrvport", "" ) == "")
        tmpport = ACCT_PORT;
    else
        tmpport = atoi( ( vs_config->getVariable( "network", "accountsrvport", "" ) ).c_str() );
    Network = NetworkToClient.createServerSocket( tmpport, _sock_set );
    if (!Network) {
        cout<<"Error cannot start server... quitting."<<endl;
        VSExit( 1 );
    }
    cout<<"done."<<endl;

    _sock_set.start();
    while (keeprun) {
        COUT<<"Loop"<<endl;
        //Check for incoming connections

        _sock_set.wait();

        comsock = Network->acceptNewConn();
        if ( comsock.valid() ) {
            Socks.push_back( comsock );
            COUT<<"New connection - socket allocated : "<<comsock<<endl;
        }
        //Loop for each active client and process request
        list< SOCKETALT >::iterator i;
        for (i = Socks.begin(); i != Socks.end(); i++) {
            SOCKETALT alt( *i );
            if ( alt.isActive() )
                this->recvMsg( alt );
        }
        //Remove dead connections
        this->removeDeadSockets();
        //Check for automatic server status save time
        curtime = getNewTime();

        //micro_sleep(40000);
    }
    delete CONFIGFILE;
    delete vs_config;
    vs_config = NULL;
    Network->disconnect( "Shutting down." );
}

void AccountServer::recvMsg( SOCKETALT sock )
{
    string        callsign, passwd;
    int           recvcount = 0;
    unsigned char cmd;
    Account      *elem = NULL;
    int           found     = 0, connected = 0;

    //Receive data from sock
    Packet        p;
    AddressIP     ipadr;
    if ( ( recvcount = sock.recvbuf( &p, &ipadr ) ) > 0 ) {
        cout<<"Socket : "<<endl<<sock<<endl;
        packet = p;
        NetBuffer netbuf( packet.getData(), packet.getDataLength() );
        //Check the command of the packet
        cmd    = packet.getCommand();
        cout<<"Buffer => "<<p.getData()<<endl;
        VI j;
        switch (cmd)
        {
        case LOGIN_DATA:
            //We receive a request from a client that wants to know to which game server he has to connect to
            callsign = netbuf.getString();
            passwd   = netbuf.getString();
            cout<<">>> SERVER REQUEST =( "<<callsign<<":"<<passwd<<" )= --------------------------------------"<<endl;
            elem     = getAcctTemplate( callsign );
            if (elem)
                if (elem->passwd != passwd)
                    elem = NULL;
            if (!elem) {
                COUT<<"Login/passwd not found"<<endl;
                Account elt( callsign, passwd );
                this->sendUnauthorized( sock, &elt );
            } else {
                if (elem->isConnected() && elem->retryConnectedCount() < 6) {
                    COUT<<"Login already connected !"<<endl;
                    //elem->incConnected();//right now causes fatal clientside error
                    this->sendAlreadyConnected( sock, elem );
                } else {
                    COUT<<"Login accepted send server ip !"<<endl;
                    //Send a packet with server IP Address
                    this->sendServerData( sock, elem );
                    //elem->setConnected( true);
                }
            }
            break;
        case CMD_LOGIN:
            {
                char flags = netbuf.getChar();
                callsign = netbuf.getString();
                passwd   = netbuf.getString();
                cout<<">>> LOGIN REQUEST =( "<<callsign<<":"<<passwd<<" )= --------------------------------------"<<endl;
                elem     = getAcctTemplate( strtoupper( callsign ) );
                if (elem)
                    if (elem->passwd != passwd)
                        elem = NULL;
                if (!elem) {
                    Account elt( callsign, passwd );
                    this->sendUnauthorized( sock, &elt );
                } else {
                    if (elem->isConnected() && elem->retryConnectedCount() < 6) {
                        cout<<"Client already connected"<<endl;
                        //elem->incConnected();//right now causes fatal clientside error
                        this->sendUnauthorized( sock, elem );
                    } else {
                        cout<<"Login accepted !"<<endl;
                        this->sendAuthorized( sock, elem );
                        elem->setConnected( true );
                    }
                }
                cout<<"<<< LOGIN REQUEST ------------------------------------------"<<endl;
                break;
            }
        case CMD_LOGOUT:
            callsign = netbuf.getString();
            passwd   = netbuf.getString();
            cout<<">>> LOGOUT REQUEST =( "<<callsign<<":"<<passwd<<" )= --------------------------------------"<<endl;
            //Receive logout request containing name of player

            elem = getAcctTemplate( callsign );
            if (elem)
                if (elem->passwd != passwd)
                    elem = NULL;
            if ( elem && elem->isConnected() )
                connected = 1;
            else
                connected = 0;
            if (!elem) {
                cout<<"ERROR LOGOUT -> didn't find player to disconnect = <"<<callsign<<">:<"<<passwd<<">"<<endl;
            } else {
                if (connected) {
                    elem->setConnected( false );
                    cout<<"-= "<<callsign<<" =- Disconnected"<<endl;
                } else {
                    cout<<"ERROR LOGOUT -> player exists but wasn't connected ?!?!"<<endl;
                }
            }
            cout<<"<<< LOGOUT REQUEST ---------------------------------------"<<endl;
            break;
        case CMD_NEWSUBSCRIBE:
            {
                cout<<">>> SUBSRIBE REQUEST =( "<<callsign<<" )= --------------------------------------"<<endl;

                //Should receive a new subscription
                callsign = netbuf.getString();
                passwd   = netbuf.getString();
                //Loop through accounts to see if the required callsign already exists
                bool   found = false;
                Packet packet2;
                if ( 1 || getAcctNoReload( callsign ) ) {
                    found = true;
                    if (packet2.send( LOGIN_ERROR, packet.getSerial(), (char*) NULL, 0, SENDRELIABLE, NULL, sock, __FILE__,
                                      __LINE__ ) < 0) {
                        cout<<"ERROR sending authorization"<<endl;
                        exit( 1 );
                    }
                }
                if (!found) {
                    //Add the account at the end of accounts.xml
                    VSFile  f;
                    VSError err = f.OpenReadOnly( "accounts.xml", AccountFile );
                    if (err > Ok) {
                        cout<<"ERROR opening accounts file";
                        if (packet2.send( (Cmd) 0, packet.getSerial(), (char*) NULL, 0, SENDRELIABLE, NULL, sock, __FILE__,
                                         __LINE__ ) < 0)
                            cout<<"ERROR sending errormsg to subscription website"<<endl;
                        VSExit( 1 );
                    } else {
                        cout<<"Account file opened"<<endl;
                        char *fbuf = new char[MAXBUFFER+1];
                        fbuf[MAXBUFFER] = '\0';
                        vector< string >acctlines;
                        //Read a line per account and one line for the "<ACCOUNTS>" tag
                        while (f.ReadLine( fbuf, MAXBUFFER ) == Ok) {
                            acctlines.push_back( fbuf );
                            cout<<"Read line : "<<fbuf<<endl;
                        }
                        f.Close();
                        err = f.OpenCreateWrite( "accounts.xml", AccountFile );
                        if (err > Ok) {
                            cerr<<"!!! ERROR : opening account file in write mode !!!"<<endl;
                            VSExit( 1 );
                        }
                        acctlines.push_back( "\t<PLAYER name=\""+callsign+"\"\tpassword=\""+passwd+"\" />\n" );
                        acctlines.push_back( "</ACCOUNTS>\n" );
                        //cout<<"Adding to file : "<<acctstr<<endl;
                        for (size_t i = 0; i < acctlines.size(); i++)
                            if (f.WriteLine( acctlines[i].c_str() ) < 0) {
                                f.Close();
                                cout<<"!!! ERROR : writing to account file !!!"<<endl;
                                VSExit( 1 );
                            }
                        /*
                         *  if( fputs( acctstr.c_str(), fp) < 0)
                         *  {
                         *   cout<<"ERROR writing new account to account file"<<endl;
                         *   VSExit(1);
                         *  }
                         */
                        f.Close();
                        addAcct( callsign, new Account( callsign, passwd ) );
                    }
                    if (packet2.send( packet.getCommand(), packet.getSerial(), (char*) NULL, 0, SENDRELIABLE, NULL, sock,
                                      __FILE__, __LINE__ ) < 0) {
                        cout<<"ERROR sending authorization"<<endl;
                        exit( 1 );
                    }
                }
                //DeadSocks.push_back( sock);
                cout<<"<<< SUBSRIBE REQUEST --------------------------------------"<<endl;
                break;
            }
        case CMD_RESYNCACCOUNTS:
            {
                cout<<">>> RESYNC ACCOUNTS --------------------------------------"<<endl;
                ObjSerial   nbclients = packet.getSerial();
                int i = 0;
                cout<<">>>>>>>>> SYNC RECEIVED FOR "<<nbclients<<" CLIENTS <<<<<<<<<<<<"<<endl;
                std::string nameTmp;
                VI vi;
                //Loop through accounts
                //Maybe not necessary since when we get a game server disconnect we should have
                //set all its accounts disconnected
                //Loop through received client serials
                for (i = 0; i < nbclients; i++) {
                    nameTmp = netbuf.getString();
                    //sertmp = ntohs( *( (ObjSerial *)(buf+sizeof( ObjSerial)*i)));
                    //Loop through accounts
                    elem    = getAcctTemplate( callsign );
                    if (elem) {
                        //Reactivate the serial we received from server
                        if ( elem->compareName( nameTmp ) )
                            elem->setConnected( true );
                    }
                }
                cout<<"<<< RESYNC'ED ACCOUNTS --------------------------------------"<<endl;
                break;
            }
        case CMD_SAVEACCOUNTS:
            cout<<">>> SAVING ACCOUNT #"<<packet.getSerial()<<"-----------------------------"<<endl;
            this->writeSave( packet.getData(), packet.getDataLength() );
            cout<<"<<< ACCOUNT SAVED --------------------------------------"<<endl;
            break;
        default:
            cout<<">>> UNKNOWN command =( "<<cmd<<" )= ---------------------------------";
        }
        //cout<<"end received"<<endl;
    }
    /*
     *  else if( recvcount==0)
     *  {
     *   // SOCKET should have been closed by that game server
     *   cout<<"Received 0 data on socket "<<sock<<endl;
     *  }
     */
    else {
        cout<<"Received failed or socket closed"<<endl;
        DeadSocks.push_back( sock );
    }
}

void AccountServer::sendAuthorized( SOCKETALT sock, Account *acct )
{
    //Get a serial for client
    //ObjSerial serial = getUniqueSerial();
    ObjSerial serial = 0;
    acct->setSerial( serial );
    cout<<"\tLOGIN REQUEST SUCCESS for <"<<acct->callsign<<">:<"<<acct->passwd<<">"<<endl;
    //Store socket as a game server id
    acct->setSocket( sock );
    //Verify that client already has a ship or if it is a new account
    if ( acct->isNew() ) {
        //Send a command to make the client create a new character/ship
        Packet packet2;
        if (packet2.send( LOGIN_NEW, serial, packet.getData(), packet.getDataLength(), SENDRELIABLE, NULL, sock, __FILE__,
                          __LINE__ ) < 0) {
            cout<<"ERROR sending authorization"<<endl;
            exit( 1 );
        }
        //Should receive an answer from game server that contains ship's creation info to
        //be saved on the account server
    } else {
        NetBuffer netbuf;

        //Try to open save file
        string    acctfile = acct->callsign+".save";
        cerr<<"Trying to open : "<<acctfile<<endl;
        VSFile    f;
        VSError   err = f.OpenReadOnly( acctfile, AccountFile );
        if (err > Ok) {
            cerr<<"Account save file does not exists... sending default one to game server"<<endl;
            acctfile = "default.save";
            cerr<<"Trying to open : "<<acctfile<<endl;
            err = f.OpenReadOnly( "default.save", AccountFile );
            if (err > Ok) {
                cout<<"Error, default save not found"<<endl;
                VSExit( 1 );
            }
        } else {
            cout<<"... done !"<<endl;
            //Try to open xml file
        }
        string acctsave;
        //If we loaded default save -> we must load default xml
        if (acctfile == "default.save")
            acctsave = "default.xml";
        else
            acctsave = acct->callsign+".xml";
        cerr<<"Trying to open : "<<acctsave<<endl;
        VSFile  f2;
        VSError err2 = f2.OpenReadOnly( acctsave, AccountFile );
        if (err2 > Ok) {
            cout<<"XML save file does not exists... sending default one to game server"<<endl;
            acctsave = "default.xml";
            cerr<<"Trying to open : "<<acctsave<<endl;
            if (acctfile != "default.save") {
                //We loaded an existing save but no corresponding xml file so load default
                f.Close();
                cerr<<"Default XML Loaded -> reload the default save !"<<endl;
                acctfile = "default.save";
                cerr<<"Trying to open : "<<acctfile<<endl;
                err = f.OpenReadOnly( acctfile.c_str(), AccountFile );
            }
            err2 = f2.OpenReadOnly( acctsave.c_str(), AccountFile );
        } else {
            cout<<"... done !"<<endl;
        }
        string savebuf;
        string xmlbuf;

        cout<<"Save size = "<<f.Size()<<" - XML size = "<<f2.Size()<<endl;
        cout<<"Loaded -= "<<acct->callsign<<" =- save files ("<<( f.Size()+f2.Size() )<<")"<<endl;
        //Read the save unit file
        if (err <= Ok) {
            savebuf = f.ReadFull();
            f.Close();
        } else {
            cout<<"Error, default save not found"<<endl;
            VSExit( 1 );
        }
        //Put the name and passwd of the player in the packet
        netbuf.addString( acct->callsign );
        netbuf.addString( acct->passwd );
        netbuf.addString( acct->serverip );
        netbuf.addString( acct->serverport );
        //Put the size of the first save file in the buffer to send
        netbuf.addString( savebuf );
        //Read the XML file
        if (err2 <= Ok) {
            xmlbuf = f2.ReadFull();
            f2.Close();
        } else {
            cout<<"Error, default xml not found"<<endl;
            VSExit( 1 );
        }
        netbuf.addString( xmlbuf );

        Packet packet2;
        if (packet2.send( LOGIN_ACCEPT, serial,
                          netbuf.getData(), netbuf.getDataLength(),
                          SENDRELIABLE|COMPRESSED,
                          NULL, sock, __FILE__, __LINE__ ) < 0) {
            cout<<"ERROR sending authorization"<<endl;
            exit( 1 );
        }
    }
}

void AccountServer::sendUnauthorized( SOCKETALT sock, Account *acct )
{
    Packet packet2;
    packet2.send( LOGIN_ERROR, 0, packet.getData(), packet.getDataLength(), SENDRELIABLE, NULL, sock, __FILE__, __LINE__ );
    cout<<"\tLOGIN REQUEST FAILED for <"<<acct->callsign<<">:<"<<acct->passwd<<">"<<endl;
}

void AccountServer::sendAlreadyConnected( SOCKETALT sock, Account *acct )
{
    Packet packet2;
    packet2.send( LOGIN_ALREADY, acct->getSerial(), packet.getData(),
                  packet.getDataLength(), SENDRELIABLE, NULL, sock, __FILE__, __LINE__ );
    cout<<"\tLOGIN REQUEST FAILED for <"<<acct->callsign<<">:<"<<acct->passwd<<"> -> ALREADY LOGGED IN"<<endl;
}

void AccountServer::sendServerData( SOCKETALT sock, Account *acct )
{
    Packet    packet2;
    NetBuffer netbuf;
    netbuf.addString( acct->serverip );
    netbuf.addString( acct->serverport );
    cout<<"-- sending SERVERIP="<<acct->serverip<<" - SERVERPORT="<<acct->serverport<<endl;
    packet2.send( LOGIN_DATA, 0, netbuf.getData(), netbuf.getDataLength(), SENDRELIABLE, NULL, sock, __FILE__, __LINE__ );
    cout<<"\tLOGIN DATA SENT for <"<<acct->callsign<<">:<"<<acct->passwd<<">"<<endl;
}

void AccountServer::save()
{
    //Loop through all accounts and write their status
    /*
     *  VI vi;
     *  for( vi=Cltacct.begin(); vi!=Cltacct.end(); vi++)
     *  {
     *  }
     */
}

void AccountServer::removeDeadSockets()
{
    if ( DeadSocks.empty() ) return;
    int nbc_disc = 0;
    int nbs_disc = 0;
    list< SOCKETALT >::iterator j;
    Account *elem;
    for (j = DeadSocks.begin(); j != DeadSocks.end(); j++) {
        bool found = false;
        COUT<<">>>>>>> Closing socket number "<<(*j)<<endl;
        //Disconnect all of that server clients
        elem = getAcctAddress( *j );
        if (elem) {
            //if( (*vi)->getSocket().sameAddress( (*j)))
            elem->setConnected( false );
            nbc_disc++;
            found = true;
        }
        if (!found)
            nbs_disc++;
        j->disconnect( "\tclosing socket" );
        Socks.remove( (*j) );
    }
    cout<<"\tDisconnected "<<nbc_disc<<" clients associated with that server socket"<<endl;
    cout<<"\tDisconnected "<<nbs_disc<<" non-clients sockets"<<endl;
    DeadSocks.clear();
}

void AccountServer::writeSave( const char *buffer, unsigned int length )
{
    NetBuffer netbuf( buffer, length );
    vector< string >saves = FileUtil::GetSaveFromBuffer( netbuf );
    string    xmlstr = saves[0];
    string    savestr     = saves[1];

    //Find the account associated with serial packet.getSerial();
    VI vi;
    Account *elem = getAcctSerial( packet.getSerial() );
    if (!elem) {
        //Problem, we should have found it
    } else {
        //Save the files
        FileUtil::WriteSaveFiles( savestr, xmlstr, elem->callsign );
    }
}

