#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a reception room");
  SetAmbientLight(40);
  SetInventory( ([
    TOWER_N + "/dip" : 2,
    ]) );
  SetExits( ([
    "south" : TOWER_R + "/l2e1",
    ]) );
  SetLong("This posh chamber is the reception room where most state "
         "functions are held.  The massive table could easily seat "
         "dozens of visitors, but now lies rotting with age and miscare. "
         "To the south the hallway continues out into the tower.");
  SetItems( ([
    "table" : "This is a huge oaken table which could seat dozens.",
    ]) );
  SetSmell( ([
    "default" : "The air here is stale and choked with dust.",
    ]) );
  SetListen( ([
    "default" : "The room seems to echo with banter long forgotten.",
    ]) );
}