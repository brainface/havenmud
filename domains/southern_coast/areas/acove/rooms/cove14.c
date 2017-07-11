/*pirate galleon
  Zara 8/6/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a pirate galleon");
  SetAmbientLight(50);
  SetClimate("temperate");
  SetExits( ([
      "up" : ACOVE_ROOMS + "cove11",
      ]) );
  SetLong("This appears to be a storeroom of sorts "
         "below deck. Small crates are scattered and "
         "broken on the floor. At first glance, there "
        "appears not to be much of value. The room is "
         "grimy and in disarray.");
  SetItems( ([
        ({"storeroom","room"}) : "This small room is below deck.",
         ({ "crate","crates" }) : "These crates were used for "
                                 "storage at one time. ",
        "floor" : "The floor is covered with broken crates.",
      ({"corner","corners"}) : "They are layered with years of "
                                 "accumulated grime and dirt.",
      ({"grime","dirt"}) : "Years of accumulated grime and dirt "
                                "are evident in the storeroom.",
       ({ "ship","galleon"}) : (: GetLong :),
              ]) );
  SetItemAdjectives( ([
    "crates" : ({"broken","small"}),
          ]) );
  SetSmell( ([
      "default" : "The smell of stale spices and perfume "
                 "are strong here.",
         ]) );
  SetInventory( ([
       ACOVE_NPC + "crew6" : 1,
       ]) );
}
