#include "../wood.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Reveller's Hall");
  SetExits( ([
    "out" : HWD_ROOM "/gelf8",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetInventory( ([
    HWD_NPC "/combat_trainer" : 1,
    HWD_NPC "/reveller" : 1,
    ]) );
  SetLong(
    "The Hall of the Night Revellers is a large tree which has been "
    "hollowed out enough to allow the wild-elves to practice their "
    "music in preparation for the nightly dances. The floor has a "
    "smooth, well polished surface that is best for the dancing "
    "and wild frolicking of the wild-elves."
    );
  SetListen("The tree itself seems to occasionally giggle.");
  SetSmell("The polish used on the floors leaves a faint scent.");
}
