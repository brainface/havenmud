#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("in a comfortable home");
  SetExits( ([
    "out" : LISHT_ROOM "elf/rr2",
    ]) );
  SetLong(
    "An aged but well-maintained rug is the only sign that this home is "
    "not one of total poverty. What passes for a bed could easily be a "
    "space reserved for a pet in a normal dwelling. What little material "
    "possessions can be found seem to be reserved for others. It is "
    "beyond doubt that the chief resident of this home is generous to a "
    "fault."
    );
  SetSmell("Something pleasant has been burned to make the home comfortable.");
  SetInventory( ([
    LISHT_NPC "elf_equipper" : 1,
    ]) );  
}
