/* a small pasture
    kyla 1-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pasture");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
       "north" : MANSION_ROOMS + "clearing1",
       "east" : MANSION_ROOMS + "pasture2",
       "northeast" : MANSION_ROOMS + "clearing2",
        ]) );
  SetInventory( ([
       PASTURE_NPC + "llama" : 4,
              ]) );
  SetSmell( ([
       "default" : "The smell of long grass is strong here.",
           ]) );
  SetListen( ([
       "default" : "The stomping of large hoofed animals can be heard.",
           ]) );
  SetLong("This seems to be the end of the pasture. It looks as though "
          "someone has been here recently. To the north lies a clearing and "
          "to the south is a large wall. The pasture continues to the east.");
  SetItems( ([
       "clearing" : "This appears to be a very small clearing.",
       "wall" : "This is a large wooden wall."
           ]) );
  }
