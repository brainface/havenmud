#include <lib.h>
#include "parva.h"
#include <std.h>
inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
                    P_OBJ + "/pole_blah" : 4,
                    P_OBJ + "/pole_good" : 3,
                    P_OBJ + "/pole_ch" : 1,
                    // will add clothing when std has some
                    STD_BLUNT + "copper_club" : random(2),
        STD_LOCKPICKS "newbiepicks" : 3,
                    STD_KNIFE + "hunting_knife" : random(2),
                    P_OBJ + "/worm" : 20,
               ]) );
   SetPurgeInterval(5);
}
