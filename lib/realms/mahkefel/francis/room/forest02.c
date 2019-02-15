/* Forest02
 * Foresty wagony place
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
  SetShort("A gnarly thicket");
  SetLong("Hey there's more trees.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "An eerie silence settles, only to broken by drunken "
    "singing to the south.",
  ]) );

  SetSmell( ([
    "default" : "A faint odor of burnt incense drifts about.",
  ]) );
  SetExits( ([
      "east" : FRANCIS_ROOM "fence12",
      "south"  : FRANCIS_ROOM  "forest01"
  ]) );

}
