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
 *  Vegastrike Network Server Main - written by Stephane Vaxelaire <svax@free.fr>
 */

#include <iostream>
#include <stdlib.h>
#include <string>
using std::string;
#include "networking/acctserver.h"
#include "lin_time.h"

void VSExit( int code )
{
    exit( code );
}

string getStarSystemSector( const string &in )
{
    return string( "" );
}

string GetUnitDir( string filename )
{
    return string( "" );
}

char  SERVER = 2;
float simulation_atom_var = (float) 1.0/10.0;
float audio_atom_var = (float) 1.0/18.0;
class NetClient
{};
NetClient *Network;

int main( int argc, char **argv )
{
    InitTime();
    setNewTime( ( (double) time( NULL ) )-VEGA_EPOCH );
    AccountServer *Server = new AccountServer;

    Server->start();

    delete Server;
    return 0;
}

