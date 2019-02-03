#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("arid");
  SetShort("the menagerie");
  SetLong(
     "Out to oasis room outside palace. Noth to menagerie 2."
     );
  SetSmell("");
  SetListen("");
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "north" : YOZRATH_ROOM "menagerie2",
    "out" : YOZRATH_ROOM "oasis4",
    ]) );
    
}
