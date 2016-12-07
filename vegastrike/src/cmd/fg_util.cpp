#include "savegame.h"
#include "fg_util.h"
#include "faction_generic.h"
#include <algorithm>

namespace fg_util
{
//

void itoa( unsigned int dat, char *output )
{
    if (dat == 0) {
        *output++ = '0';
        *output   = '\0';
    } else {
        char *s = output;
        while (dat) {
            *s++ = '0'+dat%10;
            dat /= 10;
        }
        *s = '\0';
        std::reverse( output, s );
    }
}

std::string MakeFactionKey( int faction )
{
    char output[16];
    output[0] = 'F';
    output[1] = 'F';
    output[2] = ':';
    itoa( faction, output+3 );
    return std::string( output );
}

bool IsFGKey( const std::string &fgcandidate )
{
    if (fgcandidate.length() > 3 && fgcandidate[0] == 'F' && fgcandidate[1] == 'G' && fgcandidate[2] == ':') return true;
    return false;
}

static std::string gFG = "FG:";

std::string MakeFGKey( const std::string &fgname, int faction )
{
    char tmp[16];
    tmp[0] = '|';
    itoa( faction, tmp+1 );
    return gFG+fgname+tmp;
}

static std::string gSS = "SS:";

std::string MakeStarSystemFGKey( const std::string &starsystem )
{
    return gSS+starsystem;
}

unsigned int ShipListOffset()
{
    return 3;
}

unsigned int PerShipDataSize()
{
    return 3;
}

bool CheckFG( std::vector< std::string > &data )
{
    bool retval = false;
    unsigned int leg = data.size();
    unsigned int inc = PerShipDataSize();
    for (unsigned int i = ShipListOffset()+1; i+1 < leg; i += inc) {
        std::string *numlanded = &data[i+1];
        std::string *numtotal  = &data[i];
        if (*numlanded != *numtotal) {
            retval     = true;
            *numlanded = *numtotal;
        }
    }
    return retval;
}

bool CheckFG( SaveGame *sg, const std::string &fgname, unsigned int faction )
{
    std::string key = MakeFGKey( fgname, faction );
    return CheckFG( sg->getMissionStringData( key ) );
}

void PurgeZeroShips( SaveGame *sg, unsigned int faction )
{
    std::string  key = MakeFactionKey( faction );
    unsigned int len = sg->getMissionStringDataLength( key );
    unsigned int i   = 0;
    while (i < len) {
        CheckFG( sg, sg->getMissionStringData( key )[i] /*flightgroup*/, faction );
        i += 1;
    }
}

void PurgeZeroShips( SaveGame *sg )
{
    for (unsigned int i = 0; i < factions.size(); ++i)
        fg_util::PurgeZeroShips( sg, i );
}

//
}

