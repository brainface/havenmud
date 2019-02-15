/* fence22
 * Hey it's more fenced in deerthings
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
  SetShort("A fenced in yard");
  SetLong("Hey look this inn exits directly into pasture.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "The muddy ground makes a squelching sound underfoot.",
  ]) );

  SetSmell( ([
    "default" : "It smells ever so not at all faintly of dung.",
  ]) );
  SetExits( ([
      "south" : FRANCIS_ROOM "inn21",
      "west"  : FRANCIS_ROOM "fence12"
  ]) );
  //SetEnter inn
}
