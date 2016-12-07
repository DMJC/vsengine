#include "faction_generic.h"
#include "cmd/unit_generic.h"
#include "mission.h"
#include "cmd/briefing.h"

varInst* Mission::call_briefing( missionNode *node, int mode )
{
    varInst *viret = NULL;

    trace( node, mode );
    if (mode == SCRIPT_PARSE) {
        string cmd = node->attr_value( "name" );
        node->script.method_id = module_briefing_map[cmd];
    }
    callback_module_briefing_type method_id = (callback_module_briefing_type) node->script.method_id;
    viret = newVarInst( VI_TEMP );
    viret->type = VAR_VOID;     //assumed void except when otherwise so stated
    if (briefing != NULL || mode != SCRIPT_RUN) {
        if (method_id == CMT_BRIEFING_addShip) {
            std::string name    = getStringArgument( node, mode, 0 );
            std::string faction = getStringArgument( node, mode, 1 );
            float x = getFloatArg( node, mode, 2 );
            float y = getFloatArg( node, mode, 3 );
            float z = getFloatArg( node, mode, 4 );
            if (mode == SCRIPT_RUN) {
                viret->int_val = briefing->AddStarship( name.c_str(),
                                                       FactionUtil::GetFactionIndex( faction ),
                                                       Vector( x, y, z ) );
            }
            viret->type = VAR_INT;
        } else if (method_id == CMT_BRIEFING_removeShip) {
            int whichship = (int) getIntArg( node, mode, 0 );
            if (mode == SCRIPT_RUN)
                briefing->RemoveStarship( whichship );
        } else if (method_id == CMT_BRIEFING_enqueueOrder || method_id == CMT_BRIEFING_replaceOrder) {
            int   whichship = (int) getIntArg( node, mode, 0 );
            float destx     = getFloatArg( node, mode, 1 );
            float desty     = getFloatArg( node, mode, 2 );
            float destz     = getFloatArg( node, mode, 3 );
            float time = getFloatArg( node, mode, 4 );
            if (mode == SCRIPT_RUN) {
                if (method_id == CMT_BRIEFING_enqueueOrder)
                    briefing->EnqueueOrder( whichship, Vector( destx, desty, destz ), time );
                else
                    briefing->OverrideOrder( whichship, Vector( destx, desty, destz ), time );
            }
        } else if (method_id == CMT_BRIEFING_getShipPosition) {
            int     whichship = (int) getIntArg( node, mode, 0 );
            QVector pos;
            if (mode == SCRIPT_RUN)
                pos = briefing->GetPosition( whichship ).Cast();
            viret->type = VAR_OBJECT;
            viret->objectname = "olist";
            call_vector_into_olist( viret, pos );
        } else if (method_id == CMT_BRIEFING_setShipPosition) {
            int   whichship = (int) getIntArg( node, mode, 0 );
            float destx     = getFloatArg( node, mode, 1 );
            float desty     = getFloatArg( node, mode, 2 );
            float destz     = getFloatArg( node, mode, 3 );
            if (mode == SCRIPT_RUN)
                briefing->SetPosition( whichship, Vector( destx, desty, destz ) );
        } else if (method_id == CMT_BRIEFING_terminate) {
            BriefingEnd();
        } else if (method_id == CMT_BRIEFING_setCamPosition) {
            QVector p( getFloatArg( node, mode, 0 ), getFloatArg( node, mode, 1 ), getFloatArg( node, mode, 2 ) );
            if (mode == SCRIPT_RUN)
                briefing->cam.SetPosition( p, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
        } else if (method_id == CMT_BRIEFING_setCamOrientation) {
            Vector p( getFloatArg( node, mode, 0 ), getFloatArg( node, mode, 1 ), getFloatArg( node, mode, 2 ) );
            Vector q( getFloatArg( node, mode, 3 ), getFloatArg( node, mode, 4 ), getFloatArg( node, mode, 5 ) );
            Vector r( getFloatArg( node, mode, 6 ), getFloatArg( node, mode, 7 ), getFloatArg( node, mode, 8 ) );
            if (mode == SCRIPT_RUN)
                briefing->cam.SetOrientation( p, q, r );
        } else if (method_id == CMT_BRIEFING_setCloak) {
            int   whichship = (int) getIntArg( node, mode, 0 );
            float cloak     = getFloatArg( node, mode, 1 );
            if (mode == SCRIPT_RUN)
                briefing->SetCloak( whichship, cloak );
        }
    }
    return viret;
}

