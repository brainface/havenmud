/* An arctic expedition at the north pole
 *
 * pier
 *
 * 
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("arctic");
  SetAmbientLight(30);
  SetShort("A long and shaky pier");
  SetLong(
    "look, it's a pier. South will be arctic sea."
  );

  SetListen( ([
    "default" : "listens.",
  ]) );

  SetSmell( ([
    "default" : "smells.",
  ]) );

  SetItems( ([
  ]) );

  SetInventory( ([
  ]) );

  SetExits( ([
    "north" : CAMP_ROOM "camp22",
    "west" : CAMP_ROOM "bay13",
  ]) );

}

