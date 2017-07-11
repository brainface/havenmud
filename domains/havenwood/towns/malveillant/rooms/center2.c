/*  Portia  12-7-98
    The center of town for the lower level.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("the center of town");
 SetObviousExits("Up, Down, N, S, E, W, SE, SW, NE, NW");
 SetClimate("underground");
 SetExits( ([
   "up" : MAL_ROOMS + "stair2",
   "down" : MAL_ROOMS3 + "stair3",
   "north" : MAL_ROOMS + "path9",
   "northeast" : MAL_ROOMS + "path10",
   "south" : MAL_ROOMS + "path13",
   "east" : MAL_ROOMS + "path11",
   "southeast" : MAL_ROOMS + "path12",
   "southwest" : MAL_ROOMS + "path14",
   "northwest" : MAL_ROOMS + "path16",
   "west" : MAL_ROOMS + "path15",
   ]) );
 SetInventory( ([
   MAL_OBJ + "/misc/well" : 1,
   MAL_NPC + "guard1" : 1,
   MAL_NPC + "guard2" : 1,
   MAL_NPC + "controller" : 1,
   ]) );
 SetListen( ([
   "default" : "There is a constant roar of commotion.",
   ]) );
 SetSmell( ([
   "default" : "The air smells of earth mixed with the faint "
     "smell of cooking.",
   ]) );
 SetLong("This level of town used to be filled with the "
   "businesses of Malveillant. Most have moved down to the "
   "third level marketplace, which has quickly become an active "
   "hub. To the east lies an enormous church and to the west lies "
   "a large hall of some sort. The large staircase continues on "
   "to the third level of Malveillant.");
 SetItems( ([
   ({"level", "level of town", "town", "malveillant"}) :
       (:GetLong:),
   ({"businesses", "business"}) : "The businesses of Malveillant "
       "occupy this level of town though some have moved to the third"
       "level marketplace.",
   ({"church"}) : "The huge church is dedicated to the worship of "
       "Alessandra the Princess of Darkness and Melchezidek the "
       "Prince of Deception.",
   ({"hall"}) : "This large hall looks very official.",
   ({"staircase"}) : "The staircase continues upward to the first "
   	"level of Malveillant as well as down to the third level.",
   ]) );
  SetAmbientLight(10);
 SetItemAdjectives( ([
   "level" : ({"second"}),
   "church" : ({"enormous", "huge", "dedicated"}),
   "hall" : ({"large", "very", "official"}),
   "staircase" : ({"large"}),
   ]) );
 }
