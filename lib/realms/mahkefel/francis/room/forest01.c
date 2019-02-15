/* Forest01
 * Foresty place starts
 * 
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetDomain("Havenwood");
  SetShort("A scattered copse");
  SetLong("Hey there's some trees.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "Trees sway in the breeze.",
  ]) );

  SetSmell( ([
    "default" : "Chimney smoke from the inn seems to unfortunately "
    "and persistently concentrate here.",
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "forest02",
      "east"  : FRANCIS_ROOM "barn11",
      "south" : FRANCIS_ROOM "clearing00",
  ]) );

}
