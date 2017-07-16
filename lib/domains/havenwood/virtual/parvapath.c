#include <lib.h>
#include <domains.h>
#define CANENTERPARVA 1
inherit LIB_ROOM;

int PreEnterParva();

varargs static void create(int x, int y) {
   room::create();
   SetShort("a path from Parva to the Havenwood");
   SetClimate("temperate");
   SetLong(
     "This path runs northeast to southwest from Parva to the Havenwood. "
     "Off to the southwest the path goes towards a small peninsula and beach "
     "that borders the Havenwood. Off to the northeast lies the seaside city "
     "of Parva. Scattered trees line the path, making the trip pleasant and "
     "scenic. Bushes grow by the pathside, and small tree stumps prove that "
     "this path has been logged to feed Parva's growth."
     );
   SetItems( ([
    ({ "path" }) :
       (: GetLong :),
    ({ "bush", "bushes" }) :
       "The bushes are thriving among the tree stumps.",
    ({ "stump","stumps" }) :
       "The tree stumps are slowly rotting away, having lost their ability to live.",
    ({ "trees", "tree" }) :
       "The trees of the Havenwood are strong and tall around here, but many were cut down.",
    ]) );
   SetItemAdjectives( ([
       "path"  : ({ "parva" }),
       "bush"  : ({ "growing" }),
       "stump" : ({ "small", "tree" }),
       ]) );
   SetSmell("The scent of the Havenwood is pleasant and inviting.");
   SetListen("The sounds of the wood chipper even at this distance.");
   SetExits( ([
     "northeast" : HAVENWOOD_VIRTUAL "parvapath/" + (x + 1) + "," + (y + 1),
     "southwest" : HAVENWOOD_VIRTUAL "parvapath/" + (x - 1) + "," + (y - 1),
     ]) );
   if (x == 10 && y == 10) {
     AddExit("northeast", HAVENWOOD_TOWNS "parva/room/path8", (: PreEnterParva :) );
    }
   if (x == 0 && y == 0) {
     AddExit("southwest", HAVENWOOD_AREAS "wood/rooms/beach17");
    }
}

int PreEnterParva() {
   if(CANENTERPARVA) return 1;
   if(immortalp(this_player())) return 1;
   else return 0;
}   
