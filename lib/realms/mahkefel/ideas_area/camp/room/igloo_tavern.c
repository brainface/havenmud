/* An arctic expedition at the north pole
 *
 * tavern with foodstuff
 *
 * should really have "the thing" references in here.
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a tavernous igloo");
  SetLong(
    "Hell yeah there's a bar."
  );

  SetListen( ([
    "default" : "Forced laughter and drunken merriment echoes from the walls.",
  ]) );

  SetSmell( ([
    "default" : "It smells just like a jar of pickles in here.",
  ]) );

  SetItems( ([
  ]) );

  SetInventory( ([
    CAMP_NPC "drunk" : 2,
    CAMP_NPC "bartender" : 1,
  ]) );
  
  SetExits( ([
    "out" : CAMP_ROOM "camp21",
  ]) );

}

