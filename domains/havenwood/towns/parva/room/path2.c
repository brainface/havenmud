#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "path3",
    "west" : PARVA_ROOM "path1",
    "south": PARVA_ROOM "path7",
    ]) );
  SetShort("a small dirt road in Parva");
  SetLong(
    "The path leads east and west from here, with an ancillary route heading off "
    "to the south. The buildings look no better here, many looking as if sheer "
    "force of will is all that holds them together. One building, lying on the "
    "north side of the path, has a sturdier look to it and appears to be smithy. "
    "Farther east the wharfs jut out into the ocean."
  );
  SetItems( ([
    ({ "building", "buildings", "smithy" }) : "Most of the buildings in Parva are decrepid and "
                                    "very near to collapse. One building by the road"
                                    "side however seems to serve as a smithy, and "
                                    "looks slightly less likely to collapse at any "
                                    "given moment.",
/*
    ({ "smithy" }) : "The smithy provides weapons and armour for the city.",
*/
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetEnters( ([
    ({"smithy"}) : PARVA_ROOM "smith",
    ]) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    PARVA_OBJ "fountain"   : 1,
    PARVA_NPC "controller" : 1,
    ]) );
}
