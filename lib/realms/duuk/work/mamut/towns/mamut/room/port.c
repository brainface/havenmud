#include <lib.h>
#include "../mamut.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a shallow coastal port");
  SetProperty("coastal", 1);
  SetExits( ([
    ]) );
  SetClimate("sub-arctic");
  SetLong(
    "From here, a small path leads to the east towards a small range of hills. "
    "A few small scattered fishing canoes lie on the beach here, indicating some "
    "sentient population nearby.  To the west, the Northern Sea stretches out into "
    "the distance."
    );
  SetInventory( ([
    ]) );
}
