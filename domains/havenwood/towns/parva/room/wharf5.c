#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : PARVA_ROOM "wharf4",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The dirt road dead ends here between the docks on the reeking sea and "
    "the decrepit buildings of Parva in front of a tavern, which appears to "
    "be well-anchored together. The road leads north toward the rest "
    "of Parva along the waterfront."
  );
  SetItems( ([
    ({ "dock", "docks" }) : "The docks are farther off to the north.",                               
    ({ "tavern" }) : "The tavern seems to be a stable and well maintained... tavern.",
    "road" : "The dirt road is a main way of Parva.",
    "sea" : "The ocean smells awful, like fish and rotting things.",
    "buildings" :
     "The buildings look as though they might disintegrate in a minute.",
    ]) );
  SetItemAdjectives( ([
    "sea" : ({"reeking"}),
    "buildings" : ({"decrepit"}),
    ]) );
  SetEnters( ([
    "tavern" : PARVA_ROOM "tavern",
    ]) );
  SetSmell("The stench of the sea assaults the air.");
  SetListen("At all hours, the tavern is alive with raucous noise.");
  SetInventory( ([
    PARVA_NPC "drunk" : 2,
    ]) );
}
