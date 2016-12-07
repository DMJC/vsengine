#ifndef __UNIT_ARMOR_SHIELD_H
#define __UNIT_ARMOR_SHIELD_H

#include <algorithm>

///Armor values: how much damage armor can withhold before internal damage accrues
struct Armor
{
    float frontlefttop, backlefttop, frontrighttop, backrighttop, frontleftbottom, backleftbottom, frontrightbottom,
          backrightbottom;

    Armor()
        : frontlefttop( 0 )
        , backlefttop( 0 )
        , frontrighttop( 0 )
        , backrighttop( 0 )
        , frontleftbottom( 0 )
        , backleftbottom( 0 )
        , frontrightbottom( 0 )
        , backrightbottom( 0 ) {}
};
#define MAX_SHIELD_NUMBER 8
struct ShieldFacing
{
    ShieldFacing()
        : thetamin(0.0)
        , thetamax(0.0)
        , rhomin(0.0)
        , rhomax(0.0)
    {}

    float thetamin;
    float thetamax;
    float rhomin;
    float rhomax;
};
///Shielding Struct holding values of current shields
struct Shield
{
    ///How much the shield recharges per second
    float recharge;
    float efficiency;
    //A union containing the different shield values and max values depending on number
    union
    {
        ///if shield is 2 big, 2 floats make this shield up, and 2 floats for max {front,back,frontmax,backmax}
        struct
        {
            float front, back;
            float padding[6];
            float frontmax, backmax;
        }
        shield2fb;
        ///If the shield if 4 big, 4 floats make the shield up, and 4 keep track of max recharge value
        struct
        {
            float front, back, right, left;
            float padding[4];
            float frontmax, backmax, rightmax, leftmax;
        }
        shield4fbrl;
        ///If the shield is 8 sided, 16 floats make it up
        struct
        {
            float frontrighttop, backrighttop, frontlefttop, backlefttop, frontrightbottom, backrightbottom, frontleftbottom,
                  backleftbottom;
            float frontrighttopmax, backrighttopmax, frontlefttopmax, backlefttopmax, frontrightbottommax, backrightbottommax,
                  frontleftbottommax, backleftbottommax;
        }
        shield8;
        struct
        {
            float cur[MAX_SHIELD_NUMBER];
            float max[MAX_SHIELD_NUMBER];
        }
        shield;
    };
    ShieldFacing range[MAX_SHIELD_NUMBER];
    ///the number of shields in the current shielding struct
    signed char  number;
    ///What percentage leaks (divide by 100%)
    char  leak;

    Shield()
        : recharge(0)
        , efficiency(0)
        , number(0)
        , leak(0)
    {
        std::fill_n(shield.cur, sizeof(shield.cur)/sizeof(shield.cur[0]), 0.0f);
        std::fill_n(shield.max, sizeof(shield.max)/sizeof(shield.max[0]), 0.0f);
        std::fill_n(range, sizeof(range)/sizeof(range[0]), ShieldFacing());
    }
};

#endif

