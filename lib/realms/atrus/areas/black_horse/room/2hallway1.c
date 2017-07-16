/* 2hallway1.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the upstairs hallway");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "west" : "2hallway2",
    "north" : "moes_room",
    ]) );
  SetLong(
         "Large Bar room."
          );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
    BHI_OBJ "stair2" : 1,
  ]) );
  SetSmell("bar stench.");
  SetListen("bar sounds");
  SetItemAdjectives( ([
    "door" : ({ "large", "heavy", "black" }),
    ]) );
  SetDoor("north", BHI_OBJ "moes_door");
 }
