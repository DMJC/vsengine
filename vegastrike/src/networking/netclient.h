/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
 *  NetClient - Network Client Interface - written by Stephane Vaxelaire <svax@free.fr>
 */

#ifndef __NetClient_H
#define __NetClient_H

#include "config.h" //for NETCOMM & ZLIB

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include "savegame.h"
#include "networking/const.h"
#include "networking/lowlevel/vsnet_socket.h"
#include "networking/lowlevel/vsnet_sockethttp.h"
#include "networking/lowlevel/vsnet_socketset.h"
#include "networking/lowlevel/vsnet_cmd.h"
#include "networking/lowlevel/netbuffer.h"

#include "cmd/container.h"   //for UnitContainer
#include "gfx/quaternion.h"  //for Transformation

#include "networking/clientptr.h"

class Packet;
class Unit;
class Client;
class ClientState;
class NetUI;
class NetworkCommunication;
class Prediction;

namespace VsnetDownload
{
namespace Client
{
class Manager;
};
};

using std::vector;
using std::string;
extern vector< ObjSerial >localSerials;
extern bool isLocalSerial( ObjSerial sernum );

extern ObjSerial CLIENT_NETVERSION;

class NetClient
{
    class ClientsMap
    {
        ClientMap _map;

public:
        ClientPtr insert( int x, Client *c );
        ClientPtr get( int x );
        bool remove( int x );
    };

    UnitContainer    game_unit;                         //Unit struct from the game corresponding to that client

    string _serverip;                       //used during login
    unsigned short   _serverport;           //used during login
    SOCKETALT       *clt_tcp_sock;                      //Comm. socket...memory allocated in class
    SOCKETALT       *clt_udp_sock;                      //Comm. socket...memory allocated in class
    SOCKETALT       *lossy_socket;                              //Usually points to the UDP socket, unless behind firewall... do not free this one
    VsnetHTTPSocket *acct_sock;                                         //Connection socket for account server
    SocketSet  _sock_set;                   //Encapsulates select()
//SaveGame			save;
    ObjSerial  netversion;
public:
    ObjSerial  serial;                                          //Serial # of client
private:
    int        nbclients;                                               //Number of clients in the zone
    int        zone;                                                    //Zone id in universe
    char       keeprun;                                         //Bool to test client stop
    string     callsign;                                        //Callsign of the networked player
    string     password;                                        //Callsign of the networked player
    vector< string >ship_select_list;
    int        selected_ship;

    vector< string >lastsave;               //If [0] is empty, [1] will contain a login error message.
    string     error_message;               //Errors when logging in

    ClientsMap Clients;                                         //Clients in the same zone

//This unit array has to be changed into a map too !!
//Unit *				Units[MAXOBJECTS];			// Server controlled units in the same zone
//a vector because always accessed by their IDs

    NetworkCommunication *NetComm;

    int    enabled;                                                             //Bool to say network is enabled
//Time used for refresh - not sure still used
//int					old_time;
    double cur_time;
//unsigned int		old_timestamp;          // Previous timestamp
    unsigned int latest_timestamp;                              //Last received
    double deltatime;                                                           //Semi-ping value between this client and server in ms
//double				elapsed_since_packet;	// Time elapsed since we we received the last SNAPSHOT or PING packet
    bool   jumpok;
    bool   ingame;
    float  current_freq;
    float  selected_freq;

    boost::shared_ptr< VsnetDownload::Client::Manager >_downloadManagerClient;
    static const char *_downloadSearchPaths[];

    void versionBuf( NetBuffer &buf ) const;              //Sets the netbuffer to this version.
    void createChar();
    int recvMsg( Packet *outpacket, timeval *timeout = NULL );
    void disconnect();
    int checkAcctMsg();

    void receiveLocations( const Packet *packet );
    void receiveUnitDamage( NetBuffer &netbuf, Unit *un );
    void receivePositions( unsigned int numUnits, unsigned int timestamp, NetBuffer &netbuf, double deltat );
    Unit * enterClient( NetBuffer &netbuf, ObjSerial ser );
    void removeClient( const Packet *packet );

public: NetClient();
    void Reinitialize();            //sets all values back to defaults
    ~NetClient();

    int connectLoad( string user, string pass, string &error );           //First step of loading... returns ships.
    vector< string > * loginSavedGame( int ship = 0 );      //Second half of loading process... returns savegame
    void startGame();             //Third half of loading process.

/**** netclient_login.cpp stuff ****/
    void SetConfigServerAddress( string &host, unsigned short &port );              //reads config vars, sets address/port and returns them.

    void GetCurrentServerAddress( string &host, unsigned short &port );
    void SetCurrentServerAddress( string host, unsigned short port );

//Returns the list of valid ships to use upon logging in.
    const vector< string >& shipSelections()
    {
        return ship_select_list;
    }
    bool selectShip( unsigned int ship );

    int authenticate();
    int loginAuth( string str_callsign, string str_passwd, string &error );            //Loops until receiving login response
    int loginLoop( string &error );
    vector< string >& loginAcctLoop( string str_callsign, string str_passwd );
    void loginAccept( Packet &p1 );
    void loginChooseShip( Packet &p1 );
    SOCKETALT init( const char *addr, unsigned short port, string &error );
    VsnetHTTPSocket * init_acct( const std::string &addr );
    void synchronizeTime( SOCKETALT* );              //Sends time packets back and forth to find the actual double time on the server.

//start() should not used...  Use init() instead.
//void	start( char * addr, unsigned short port);
//void	checkKey();

    void setCallsign( char *calls )
    {
        this->callsign = string( calls );
    }
    void setCallsign( string calls )
    {
        this->callsign = calls;
    }
    string getCallsign()
    {
        return this->callsign;
    }
    void setUnit( Unit *un )
    {
        game_unit.SetUnit( un );
    }
    Unit * getUnit()
    {
        return game_unit.GetUnit();
    }

/********************* Network stuff **********************/
//Get the lag time between us and the server
    unsigned int getLag()
    {
        return (unsigned int) (deltatime*1000);
    }
//Check if it is time to send our update
    int isTime();
//Warn the server we are leaving the game
    SOCKETALT * logout( bool leaveUDP );
    void Respawn( ObjSerial clientname );
    void saveRequest();
    void dieRequest();

//Check if there are info incoming over the network
    int checkMsg( Packet *outpacket );
//Send a position update

    void send( Cmd cmd, NetBuffer &netbuf, int mode, const char *file, int line );
    void sendCustom( string cmd, string args, string id );
    void sendPosition( const ClientState *cs );
    void sendCloak( bool engage );
//Send a PING-like packet to say we are still alive (UDP)
    void sendAlive();
    void inGame();                              //Tells the server we are ready to go in game
    bool isInGame()
    {
        return this->ingame;
    }

    Transformation Interpolate( Unit *un, double addtime );

//void	disable() { enabled=false;}
//int		isEnabled() { return enabled; }
//void	setNetworkedMode( bool mode) { enabled = mode;}

/********************* Weapon stuff **********************/
//Functions called when to give a firing order to the server (only for player units).
    void scanRequest( Unit *target );
    void targetRequest( Unit *target );
    void respawnRequest();
    void textMessage( const string &data );
    void fireRequest( ObjSerial serial, const vector< int > &mount_indicies, char mis );
    void unfireRequest( ObjSerial serial, const vector< int > &mount_indicies );

    void cargoRequest( ObjSerial buyer,
                       ObjSerial seller,
                       const std::string &cargo,
                       unsigned int quantity,
                       int mountOffset,
                       int subunitOffset );
    void shipRequest( const std::string &cargo, unsigned char type );
    void missionRequest( unsigned short packetType, string mission, int pos );
    void communicationRequest( const class CommunicationMessage &c, ObjSerial sendTo );
    void downloadZoneInfo();
    void AddObjects( NetBuffer &netbuf );
    ClientPtr AddClientObject( Unit *un, ObjSerial cltserial = 0 );

    bool jumpRequest( string newsystem, ObjSerial jumpserial );
    bool readyToJump();
    void unreadyToJump();

/********************* Docking stuff **********************/
    void dockRequest( ObjSerial utdw_serial );
    void undockRequest( ObjSerial utdw_serial );

/********************* Communication stuff **********************/
private:
public:
    void createNetComm( float minfreq, float maxfreq, bool video, bool secured, string method );
    void destroyNetComm();
    void startCommunication();
    void stopCommunication();
    void startWebcamTransfer();
    void stopWebcamTransfer();
    void sendWebcamPicture();
    char * getWebcamCapture();
    char * getWebcamFromNetwork( int &length );
    void increaseFrequency();
    void decreaseFrequency();
    float getSelectedFrequency();
    float getCurrentFrequency();
    void switchSecured();
    void switchWebcam();
    bool hasWebcam();

    void sendTextMessage( string message );
    bool IsNetcommActive() const;
    bool IsNetcommSecured() const;
    static void Reconnect( std::string srvipaddr, unsigned short port );
    static void CleanUp();
private: NetClient( const NetClient& );
    NetClient& operator=( const NetClient& );
};

Unit * getNetworkUnit( ObjSerial cserial );
bool isLocalSerial( ObjSerial sernum );

extern vector< ObjSerial >localSerials;
void Reconnect( std::string ip, std::string port );
#endif

