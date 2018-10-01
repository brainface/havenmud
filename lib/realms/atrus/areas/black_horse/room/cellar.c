/* cellar.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("cellar of the Black Horse Inn");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "east" : "cellar2",
    ]) );
  SetLong(
         "Dank basement."
          );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
    BHI_OBJ "stairb" : 1,
  ]) );
  SetSmell("Dank.");
  SetListen("Drips");
 }
