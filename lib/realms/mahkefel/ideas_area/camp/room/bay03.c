/* An arctic expedition at the north pole
 *
 * bay
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
  SetShort("A frigid arctic bay");
  SetLong(
    "look, it's a bay. Will have infected penguins or somethin'. "
    "South is arctic sea. Floating ice allows standing around, so coastal."
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
    "east" : CAMP_ROOM "bay13",
  ]) );

}

