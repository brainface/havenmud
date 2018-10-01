/* 2hallway1.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the attic");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "north" : "moe_store",
    ]) );
  SetLong(
         "Large Bar room."
          );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
    BHI_OBJ "stair3" : 1,
  ]) );
  SetSmell("bar stench.");
  SetListen("bar sounds");
  SetItemAdjectives( ([
    "door" : ({ "large", "heavy", "black" }),
    ]) );
  SetDoor("north", BHI_OBJ "moe_store_door");
 }
