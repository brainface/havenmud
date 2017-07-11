#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : GUROV_ROOM "keep2",
    ]) );
  SetShort("the Office of the Treasurer");
  SetLong(
    "The Office of the Treasurer is a secure room filled mostly "
    "with papers stacked high on desks. The desks appear to be "
    "functional but not rich, and the chairs appear comfortable "
    "only due to long hours spent working grooves into them. Off "
    "to the west lies the main reception hall of the Keep, but "
    "this office seems to have little to do with reception of "
    "any kind."
    );
  SetSmell("Smells of paper and drying ink hang in the air.");
  SetListen("occasionally, a piece of paper will shuffle.");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetItems( ([
    ({ "desks", "desk" }) : "The desks are sturdy but of low quality.",
    ({ "chair", "chairs" }) : "The chairs do not look overly comfortable.",
    ({ "paper", "papers" }) : "The papers have various numbers on them, "
                              "none of which mean much to a non-accountant.",
    ]) );
  SetInventory( ([
    GUROV_NPC "treasurer" : 1,
    ]) );
}