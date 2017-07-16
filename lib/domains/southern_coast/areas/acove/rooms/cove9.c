 /*ship6
zara 8/5/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;


static void create() {
room::create();

SetShort("a pirate galleon");

SetClimate("temperate");
  SetAmbientLight(50);

SetExits( ([
        "east" : ACOVE_ROOMS + "cove10",
       "down" : ACOVE_ROOMS + "cove17",
        "west" : ACOVE_ROOMS + "cove12",
       ]) );

  SetLong("Looking at this section of the ship below deck, one can "
         "almost imagine what it must have been like when "
        "this great galleon was still in its prime, "
         "sailing the high seas. A large gleaming cannon "
        "rests where it has for a hundred years. Oddly, "
         "the great gun looks as though it is well cared "
        "for and it shines from repeated polishings.");

SetItems( ([
       ({"section","ship","it","galleon"}) : "This ship has been "
                                           "here for some time and "
                                           "appears to be deserted.",
       ({"gun","cannon"}) : "This ornate cannon looks as though "
                               "it has fought many battles at sea. ", 
         "deck" :   "The planks on the deck are made of oak.",
      ]) );
  SetInventory( ([
      ACOVE_NPC + "crew2" : 1,
     ]) );
}
