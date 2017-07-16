#include <lib.h>
inherit LIB_STOREROOM;
#include "../soleil.h"
#include <std.h>
static void create() {
   storeroom::create();
   SetInventory( ([
                    STD_INSTRUMENTS + "/drum" : 4,
                    STD_INSTRUMENTS + "/fife" : 4,
                    STD_INSTRUMENTS + "/lyre" : 4,
                    STD_INSTRUMENTS + "/mandolin" : 4,
                    STD_INSTRUMENTS + "/recorder" : 4,
                    STD_INSTRUMENTS + "/spinet" : 2,
                    STD_INSTRUMENTS + "/sabbek" : 1,
                    STD_INSTRUMENTS + "/sackbut" : 10,
               ]) );
   SetPurgeInterval(5);
}
