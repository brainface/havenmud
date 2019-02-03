#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "cr9",
    "south" : GUROV_ROOM "cr7",
    "east"  : GUROV_ROOM "pr1",
    ]) );
  SetShort("the crossing of Center Road and the Prince's Road");
  SetLong(
    "The Center Road meets the Prince's Road here in a 'T' crossing. "
    "To the north the road meets up with the Gurov Docks which line "
    "the Bay, while to the south the Cathedral of Three Gods can be seen "
    "near the road. Further east, the Prince's Road travels to the "
    "Keep of the Prince. The cemetery of Gurov lies to the south."
    );
  SetItems( ([
    "cathedral" : "The Cathedral of Three Gods rises to the southwest.",
    "keep"      : "The Keep is to the east.",
    "cemetery"  : "The cemetery is to the south.",
    ]) );
  SetSmell("The gentle waft of the bay can barely be felt here.");
  SetListen("Many sounds mingle, waves from the bay, "
            "carts, and the bells of the Cathedral.");
  SetInventory( ([
    ]) );
}