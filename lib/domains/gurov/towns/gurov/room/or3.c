#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "or4",
    "west" : GUROV_ROOM "cr1",
    ]) );
  SetShort("the Outer Road along the city wall");
  SetLong(
    "The Outer Road continues to the east and west from here. To the east, "
    "the road seems to curve to follow the line of the town wall, while to "
    "the west the road meets up with the Center Road and heads into the "
    "city itself. The town wall rises twenty feet into the sky, towering "
    "over and protecting the city from harm."
    );
  SetSmell("The smell of pack animals comes from the west.");
  SetListen("Sounds quietly echo off the giant town wall."); 
}