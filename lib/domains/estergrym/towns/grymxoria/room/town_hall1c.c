#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Town Hall of Grymxoria");
  SetLong(
    "The office of the Warlord of Grymxoria. Fine tapestries adorn "
    "the otherwise bare stone walls. A large wooden desk "
    "sits in the center of the room."
  );
  SetItems( ([
    ({ "tapestries" }) : "Fine tapestries depicting the history of "
    "the town of Grymxoria.",
    ({ "desk" }) : "A large desk made out of good, hard, wood."]) );
  SetExits( ([ 
    "down" : G_ROOM + "town_hall2b" 
  ]) );
  SetInventory( ([
	G_NPC +"gunthar" : 1,
  ]) );
}

