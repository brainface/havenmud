#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("outdoors");
  SetShort("the Yozrath Menagerie");
  SetLong(
     "Palace menagerie filled with various animals. Gazelle, hyena, sand cat "
     "Oryx, etc. South to indoor aviary, east to more animals."
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
    "south" : YOZRATH_ROOM "aviary",
    "east" : YOZRATH_ROOM "menagerie2",
    ]) );
    
}
