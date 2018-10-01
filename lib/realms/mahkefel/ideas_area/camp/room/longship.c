/* An arctic expedition at the north pole
 *
 * a barracks
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
  SetAmbientLight(10); // I hope this is dark?
  SetShort("a barracks");
  SetLong(
    "like beds and shit. Peeps are staying in the hull of beached ship."
  );

  SetListen( ([
    "default" : "Snoring competes with the creaking of settling wood.",
  ]) );

  SetSmell( ([
    "default" : "Yep. That's what sweat, snot, and despair smell like.",
  ]) );

  SetItems( ([
  ]) );

  SetInventory( ([
    CAMP_NPC "guard" : random(3),
    
  ]) );

  SetExits( ([
    "out" : CAMP_ROOM "camp01",
    "north" : CAMP_ROOM "longship_captain",
  ]) );

}

