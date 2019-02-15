/* Field0,0
 * An empty field in front of
 * all this wagonage
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-tropical");
  SetDomain("Havenwood");
  SetShort("A grassy clearing");
  SetLong("Clearly, it contains grass.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "Someone is snoring to wake the dead.",
  ]) );

  SetSmell( ([
    "default" : "Treesap, kicked up dust, and the bitter "
    "smoke of burnt coffee fill the air.",
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "forest01",
      "east"  : FRANCIS_ROOM  "clearing10"
  ]) );

}
