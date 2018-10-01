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
    "This is a large office of the Grymxoria town hall. "
    "Scribes, messengers, councilors, and assistants run "
    "to and fro attending to their respective tasks. "
    "At the north end of the room is a small staircase that "
    "leads up to the office of the Warlord of Grymxoria."
  );
  SetItems( ([
    ({ "stair", "staircase" }) : "A staircase of black "
    "stone, leading up."
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "town_hall3b",
    "west" : G_ROOM + "town_hall1b",
    "up" : G_ROOM + "town_hall1c"
  ]) );
}

