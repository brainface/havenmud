#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "cr5",
    "south" : GUROV_ROOM "cr3",
    "west"  : GUROV_ROOM "nr1",
    ]) );
  SetShort("the Center Road crossing Nobles' Road");
  SetLong(
    "The Center Road continues to the north and south from here. The road "
    "meets the Nobles' Road in a 'T' here, the Nobles' Road heads to the "
    "west while the Center Road continues along its path. Built directly "
    "across from the intersection is a large and sturdy smithy."
    );
  SetSmell("Soot pours from the smithy.");
  SetListen("The sounds of the forge come from the smithy.");
  SetItems( ([
    "smithy" : "This is a smithy.",
    ]) );
  SetEnters( ([
    "smithy" : GUROV_ROOM "inn",
    ]) );
}