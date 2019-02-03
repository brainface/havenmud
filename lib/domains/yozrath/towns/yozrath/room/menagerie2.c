#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("arid");
  SetShort("the menagerie");
  SetLong(
     "South to menagerie3, west to menagerie1."
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
    "west" : YOZRATH_ROOM "menagerie1",
    "south" : YOZRATH_ROOM "menagerie3",
    ]) );
    
}
