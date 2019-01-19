#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "or6",
    "south" : GUROV_ROOM "or4",
    ]) );
  SetShort("along the Outer Road");
  SetLong(
    "The Outer Road continues to follow the town wall from here, leading "
    "off to the north and south. The town wall rises twenty feet into the "
    "sky, its grey stone a fearsome sight sure to dissuade many attackers. "
    "Off to the south, the Outer Road curves with the wall and heads to the "
    "west towards the town gate. To the north, the road seems to dead end "
    "in front of two buildings."
    );
  SetSmell("The road smells of the occasional pack animal.");
  SetListen("The sounds of the city couple with the quiet of the wall.");
  SetItems( ([
    "wall" : "The town wall rises into the heights and is made of thick grey stone.",
    ]) );
}