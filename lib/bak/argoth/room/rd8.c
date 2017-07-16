#include <lib.h>
#include <domains.h>
#include "../argoth.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the shores of the Ruined Sea");
  SetExits( ([
    "north" : ARGOTH_ROOM "rd7",
    "south" : INNERSEA_VIRTUAL "ocean/-40,0",
    ]) );
  SetListen("The waves gently crash against the shoreline here.");
  SetSmell("The stench of dead fish gives the shore the smell of home.");
  SetLong(
    "The shoreline extends to view the Ruined Sea. The still waters "
    "offer no solace to the wounded soul and the dark deep of the "
    "ocean offers no guarantee of riches. To the north lies the city "
    "of Argoth and the Fortress of Karak Varn."
    );
  SetProperty("coastal", 1);
  SetInventory( ([
    ARGOTH_NPC "shiptrainer" : 1,
    ARGOTH_NPC "shipseller"  : 1,
    ]) );
}
  