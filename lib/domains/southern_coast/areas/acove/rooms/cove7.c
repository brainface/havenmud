 /*ship 4
  zara 7/31/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
 room::create();
SetShort("a pirate galleon");
 SetClimate("temperate");
 SetExits( ([
         "west" : ACOVE_ROOMS + "cove8",
         "east" : ACOVE_ROOMS + "cove4",
          ]) );
 SetLong("A deep sense of foreboding permeates this "
         "part of the ship. Bones of unknown origin "
         "litter the deck.  The planking is covered "
         "with rust-colored stains that tell the tale "
         "of those foolish enough to pass this way "
         "before. As in other parts of the ship, the "
         "evidence of unseen hands can be seen in the "
         "polished railings and weathered deck.");
 SetItems( ([
        ({"deck","planking","part","parts","ship","here"}) : "This part of the "
                                            "ship is old and weathered "
                                            "but apparantly well "
                                            "cared for.",
        ({ "bone", "bones" }) : "The bleached old bones appear "
                               "to be human. ",
       ({ "stain","stains" }) : "These stains are rust-colored and "
                                "could be blood. ",
       "evidence" : "For a deserted ship, this one "
                   "seems remarkably well cared for. ",
       ({ "ship","galleon"}) : (: GetLong :),
        ]) );
       SetInventory( ([
          ACOVE_NPC + "crew2" : 1,
          ]) );
}
