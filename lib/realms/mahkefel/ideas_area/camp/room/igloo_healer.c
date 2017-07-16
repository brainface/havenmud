/* An arctic expedition at the north pole
 *
 * healer's place
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
  SetShort("A small shrine");
  SetLong(
    "Healer's igloo. Several shrines lying around. (Kylin, Aberach, Magildan. "
    "an out of place soirin altar left by the godens.)"
  );

  SetListen( ([
    "default" : "A solemn silence fills the air.",
  ]) );

  SetSmell( ([
    "default" : "Smoky incense twirls through the air.",
  ]) );

  SetItems( ([
  ]) );

  SetInventory( ([
    CAMP_NPC "healer" : 1,    
  ]) );

  SetExits( ([
    "out" : CAMP_ROOM "camp01",
  ]) );

}

