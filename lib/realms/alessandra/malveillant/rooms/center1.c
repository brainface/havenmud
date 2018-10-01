/*
    Center of town on the first level.
    version 2.0
 */

#include <lib.h>
#include <domains.h>
#include "../mal.h"
 inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("the center of town");
 SetObviousExits("Up, Down, N, S, E, W, NE, NW, SE, SW");
 SetClimate("underground");
 SetExits( ([
  "up" : MAL_ROOMS + "stair1",
   "down" : MAL_ROOMS + "stair2",
   "north" : MAL_ROOMS + "path1",
  "northeast" : MAL_ROOMS + "path2",
   "east" : MAL_ROOMS + "path3",
   "southeast" : MAL_ROOMS + "path4",
   "south" : MAL_ROOMS + "path5",
   "southwest" : MAL_ROOMS + "path6",
   "west" : MAL_ROOMS + "path7",
   "northwest" : MAL_ROOMS + "path8",
   ]) );
 SetInventory( ([
   MAL_OBJ + "/misc/well" : 1,
   MAL_NPC + "citizen2" : 1,
   MAL_NPC + "guard1" : 1,
   MAL_NPC + "citizen1" : 1,
   ]) );
 SetListen( ([
   "default" : "The area humms with the sounds of civilization.",
   ]) );
 SetSmell( ([
   "default" : "The air smells of earth and must.",
   ]) );
 SetLong("A huge spiral staircase descending from above is the "
   "focal point of the town. It is obviously a point of pride for "
   "the citizens, as they can be seen staring at it in wonder at "
   "almost any time of day. This seems to be the residential section "
   "of town, with many paths leading to large homes. The stairway "
   "continues downward to the second level of town. To the southeast "
   "lies an enormous palace of obsidian.");
 SetItems( ([
   ({"town", "area", "center of town"}) : (:GetLong:),
   ({"staircase", "stairway"}) : "This spiral staircase is an "
       "impressive sight as it descends from the top of the "
       "cavern down to the lowest level of town.",
   ({"cavern", "top of the cavern"}) : "This large cavern houses "
       "the town of Malveillant.",
   ({"section"}) : "This is the residential section of town.",
   ({"paths", "path"}) : "Several paths lead in all directions.",
   ({"homes", "home"}) : "Large obsidian homes stand at the end "
       "of the paths.",
   ({"palace"}) : "The huge palace lies to the southeast.",
   ({"level"}) : "This is the first level of Malveillant.",
   ]) );
 SetItemAdjectives( ([
   "town" : "level of", 
   "staircase" : ({"spiral", "huge", "impressive", "obsidian"}),
   "cavern" : "large",
   "section" : ({"residential"}),
   "paths" : ({"several", "many"}),
   "homes" : ({"large", "obsidian"}),
   "palace" : ({"huge", "obsidian"}),
   "level" : ({"first"}),
   ]) );
 }
