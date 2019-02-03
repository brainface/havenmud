#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "cr6",
    "south" : GUROV_ROOM "cr4",
    ]) );
  SetShort("the Center Road north of the Nobles' Road");
  SetLong(
    "The Center Road continues to the north and south from here. "
    "To the north, the road seems to meet up with a small alley, "
    "while to the south the road meets and forms a 'T' intersection "
    "with the Nobles' Road that leads to the Council Hall. Various "
    "buildings are built along the road, but only one of them seems "
    "to hold any interest, the General Store."
    );
  SetSmell("The road is littered with the refuse from pack teams.");
  SetListen("The occasional clatter of hooves on stone breaks the quiet.");
  SetItems( ([
    ({ "building", "buildings" }) : "The buildings, while nice, offer "
                                    "nothing of value to inspection.",
    ({ "store", }) : "The General Store is a prosperous building.",               
    ]) );
  SetEnters( ([
    "store" : GUROV_ROOM "shop",
    ]) );
  SetInventory( ([
    ]) );                                    
}
