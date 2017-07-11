#include <lib.h>
#include "../../haven.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("above the Elven Charity");
  SetExits( ([
    "down" : H_ROOM "misc_buildings/charity",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong(
    "This small hall is a sleeping room above the Elven Charity. "
    "Several small sleeping cots are lined up in a neat and orderly "
    "fashion. This room has a safe, friendly feeling to it, and is "
    "the first place many young adventurers seek out as a refuge "
    "and base of operations. A well maintained clock hangs on the wall."
    );
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetListen("A regular, orderly tick comes from the clock.");
  SetInventory( ([
    H_OBJ "clock" : 1,
    ]) );
}