#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "cr4",
    "west" : GUROV_ROOM "nr2",
    ]) );
  SetShort("the Nobles' Road west of Center Road");
  SetLong(
    "The Nobles' Road heads off to the west from here and meets with "
    "the Center Road to the east. The Center Road travels the length "
    "of the town from the Gurov Bay to the town gate, making it the "
    "most widely used road in the Principality. The road itself is "
    "maintained extremely well due to the Nobles' wishes that the "
    "Council Hall be the most majestic structure in all of the land."
    );
  SetItems( ([
    ]) );
  SetSmell("The path is remarkably clean and tidy.");
  SetListen("The sounds of wagons on paving come from the east.");
}