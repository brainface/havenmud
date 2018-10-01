/* An arctic expedition at the north pole
 *
 * the captain's quarters
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
  SetAmbientLight(30); 
  SetShort("the captain's quarters");
  SetLong(
    "Maybe lying at an angle. More creature comforts than elsewhere."
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
    CAMP_NPC "captain" : 1,    
  ]) );

  SetExits( ([
    "south" : CAMP_ROOM "longship",
  ]) );

}

