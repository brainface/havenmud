#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetInventory( ([
     TOWER_N + "/guard" : 2,
     ]) );
  SetShort("inside the tower");
  SetExits( ([
    "north" : TOWER_R + "/dips",
    "west"  : TOWER_R + "/l2r1",
    ]) );
  SetAmbientLight(40);
  SetLong("This hallway extends along the eastern side of the tower. "
           "To the north is a small chamber which seems important. To "
           "the west is a staircase leading down to the main floor. "
           "This wing of the tower appears to have been used for state "
           "functions such as diplomatic receptions and other dignities.");
  SetSmell( ([
    "default" : "Dust clogs the air.",
    ]) );
  SetListen( ([
    "default" : "The silence in this hallway is dark and somber.",
    ]) );
}
