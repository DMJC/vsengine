#include <string>
#include "unit_generic.h"

VSSprite * createVSSprite( const char *file )
{
    return NULL;
}

bool isVSSpriteLoaded( const VSSprite *file )
{
    return true;
}

void deleteVSSprite( VSSprite *file ) {}

void abletodock( int ) {}

void cache_ani( std::string s ) {}

void update_ani_cache() {}

std::string getRandomCachedAniString()
{
    return "";
}

Animation * getRandomCachedAni()
{
    return NULL;
}

