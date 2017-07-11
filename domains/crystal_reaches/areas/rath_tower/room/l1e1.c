#include <lib.h>
#include "../rath.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("a small chapel");
  SetTown("Rath's Tower");
  SetClasses( ({ "cleric" }) );
  SetReligion("Rath Cult");
  SetExits( ([
    "west" : TOWER_R + "/entrance",
    ]) );
  SetAmbientLight(40);
  SetLong("This section of the tower appears to be what was once "
         "the chapel for the tower. There are pews in the room "
         "which face toward the south wall, where there is a large "
         "altar of some kind.");
  SetItems( ([
    ({ "pew", "pews" }) : "The pews are oaken and face south.",
    ({ "wall", "south wall", "southern wall" }) : "The walls are not "
                                                   "very descript, but "
                                                   "the south wall focuses "
                                                   "on a large altar.",
    ]) );
  SetInventory( ([
    TOWER_N + "/priest" : 1,
    TOWER_O + "/altar"  : 1,
    ]) );
  SetSmell( ([
    "default" : "The taint of ancient incense drifts in the air.",
    ]) );
  SetListen( ([
    "default" : "Quiet whispers seem to call to the young.",
    ]) );
}
