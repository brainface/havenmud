// Coded by Zeratul
// 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
    SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("A small clearing");
  SetDayLong("The sun rises over the area and lights it peacefully. "
     "Cut down trees lie here, with leaves strewn about under the downed "
     "trees. Cut up pieces of wood lie in a pile over on the south part "
     "of the clearing ready to be taken away. Wildlife isn't as heavy here "
     "but it is still present. "
     );
  SetNightLong("The moon loomes over the area and lights it peacefully "
    "Cut down trees lie here, with leaves strewn about under the downed "
    "trees. Cut up pieces of wood lie in a pile over on the south part "
     "of the clearing ready to be taken away. Wildlife isn't as heavy here "
     "but it is still present. "
   );
  SetListen( ([
    "default" : "Wildlife is softer here with sounds of trees being cut down. "
     ]) );
  SetSmell( ([
     "default" : "The air smells cool and crisp.",
     ]) );
  SetInventory( ([
     LAKE_NPC + "/anhinga" : 1,
     LAKE_OBJ + "/log1" : 3,
     LAKE_OBJ + "/log2" : 2,
     ]) );
  SetExits( ([
     "northeast" : LAKE_ROOM + "/cabin_out",
     ]) );
}

