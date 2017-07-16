 //Lanikai@Haven
//6-21-09
#include <lib.h>
#include <domains.h>
#include "../lumber.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetExits( ([
    "west" : LUMBER_ROOM "room1",
    ]) );
 SetShort("an abandoned lumber camp");
  SetLong(
    "This area of the camp is extremely overgrown. "
    "The forest presses in on the small area as though it is actively "
    "trying to reclaim it. Various tools are scattered about. "
        );
  SetSmell("It smells of spicy wood.");
  SetListen("The sounds of the forest encroach into the area."); 
  SetItems( ([
            ({"tools"}) :
            "These tools seem to be of the kind used in the harvesting "
            "and processing of wood.",
    ]) );
  SetInventory( ([
    LUMBER_NPC + "fur_trader" : 1,
    LUMBER_NPC + "porcupine" : 1,
    LUMBER_NPC + "fox" : 1,
  ]) );
}
