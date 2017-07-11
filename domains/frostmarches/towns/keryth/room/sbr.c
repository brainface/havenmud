#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Soirin Cleric Board Room");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(55);
  SetLong("Completely functional, this room contains nothing but a board "
          "nailed securely into the wall and a mysterious glowing sphere "
          "embedded in the ceiling, obviously there to light the room.  "
          "There is a sense of awesome power to this place.");
  SetItems( ([
    ({ "sphere", "ceiling", "light" }) :
       "The sphere is solidly embedded in the ceiling and illuminates the "
       "room.",
    ({ "wall", "walls" }) : (: GetLong :)
  ]) );
  SetItemAdjectives( ([
    "sphere" : ({ "mysterious", "glowing", "solidly embedded", "embedded" })
  ]) );
  SetExits( ([ "east" : K_ROOM + "/temple" ]) );
  SetInventory( ([
    //K_OBJ + "/soirin_cleric_board" : 1
  ]) );
  SetListen( ([
    "default" : "A low humming can be heard here.",
    "sphere" : "The sphere hums steadily with magic."
  ]) );
}
