/* fence12
 * Hey it's fenced in deerthings
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
  SetShort("A small pasture");
  SetLong("Hey look we're in a fenced in pasture.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "The muddy ground makes a squelching sound underfoot.",
  ]) );

  SetSmell( ([
    "default" : "It smells ever so not at all faintly of dung.",
  ]) );
  SetExits( ([
      "east"  : FRANCIS_ROOM "fence22",
      "south" : FRANCIS_ROOM "barn11",
      "west"  : FRANCIS_ROOM "forest02"
  ]) );

}
