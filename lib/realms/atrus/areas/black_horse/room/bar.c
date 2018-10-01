/* bar.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("bar room of the Black Horse Inn");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "east" : "bareast",
    "west" : "hallway",
    "north" : "khallway",
    ]) );
  SetLong(
         "Large Bar room."
          );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
  ]) );
  SetSmell("bar stench.");
  SetListen("bar sounds");
 }
