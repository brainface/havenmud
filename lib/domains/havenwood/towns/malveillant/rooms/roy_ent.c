/*  Portia  12-11-98
    The entrance to the palace
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("the royal entranceway");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path4",
   "south" : MAL_ROOMS + "throne",
   "east" : MAL_ROOMS + "mage",
   ]) );
 SetListen( ([
   "default" : "Many sounds can be heard from th south.",
   ]) );
 SetSmell( ([
   "default" : "The scent of food wafts in from the south.",
   ]) );
 SetInventory( ([
   MAL_NPC + "guard1" : 1,
   MAL_NPC + "guard2" : 2,
   MAL_OBJ + "/misc/poster" : 1, 
   ]) );
 SetLong("The royal entranceway way is decorated with "
   "great taste. Candles shine from the walls and flags "
   "hang from the ceiling. Two large doors are here, one "
   "leading to the south and one leading to the east. There "
   "is also a door which leads back out to the town. The "
   "entire palace seems to be heavily guarded.");
 SetItems( ([
   ({"entranceway", "palace"}) : (:GetLong:),
   ({"candles", "candle"}) : "The candles glow brightly.",
   ({"flags", "flag", "ceiling"}) : "The ceiling bears "
       "the weight of the flags of Malveillant.",
   ({"doors", "door"}) : "All of the doors seem quite heavy.",
   ]) );
 SetItemAdjectives( ([
   "entrranceway" : "royal",
   "candles" : "bright",
   "doors" : ({"heavy", "east", "south"}),
   ]) );
 }
