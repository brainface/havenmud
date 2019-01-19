#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "cr4",
    "south" : GUROV_ROOM "cr2",
    ]) );
  SetShort("along the Center Road south of an intersection");
  SetLong(
    "The Center Road continues to the north and south from here. To the "
    "north lies an intersection where another road branches off to the "
    "west. Off to the south lies the home of a Gurov family, and further "
    "into the southern distance lies the town wall and city gate. Lying "
    "off to the north near the intersection is the town smithy."
    );
  SetItems( ([
    "wall" : "The town wall is far off to the south.",
    "gate" : "The town gate is far off to the south.",
    "intersection" : "The intersection to the north is the corners of "
                     "the Center Road and the Nobles' Road.",
    "smithy" : "The smithy lies to the north.",
    ]) );
  SetSmell( ([
    "default" : "Soot from the nearby smithy tinges the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of city life rebound from all directions.",
    ]) );
}
