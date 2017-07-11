/*a pirate galleon
 Zara 8/7/98
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
    "up" : ACOVE_ROOMS + "cove9",
    ]) );
  SetLong("The feeling in this part of the ship is less "
        "oppressive. Other than that, it resembles the "
        "rest of the ship. The ornate railing gleams and the "
        "deck is swept free of litter. A three-legged stool "
       "sits off to one side.");
  SetItems( ([
      ({ "ship","part","deck" }) : "The ship here is clean "
                                   "and well maintained.",
      "railing" : "The old oak railing is worn and smooth.",
      "stool" : "The three-legged stool is made of wood and "
                "is worn from repeated use.",
      ]) );
  SetItemAdjectives( ([
  "railing" : ({"oak","old","smooth","worn"}),
   "stool" : ({"wood","three-legged","worn"}),
        ]) );
  SetSmell( ([
    "default" : "The fresh salt air smells clean.",
        ]) );
  SetListen( ([
    
    "default" : "A faint, jaunty tune reaches the ear.",
        ]) );
  SetInventory( ([
      ACOVE_NPC + "crew1" : 1,
      ]) );
}
