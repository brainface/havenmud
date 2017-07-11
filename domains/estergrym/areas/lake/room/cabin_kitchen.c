// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetDomain("Estergrym");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("A cabin kitchen");
  SetLong("Wooden walls, floor, ceiling, cabinets make up this small "
     "cabin kitchen. Polished wooden floor and cabinets make the room look "
     "nice and relaxing for preparing food. A small window hangs above "
     "the counter on the one side with a small table on the other side. "
     );
  SetListen( ([
     "default" : "Rustling and talking can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells of evergreen wood.",
     ]) );
  SetItems( ([
    ({"walls","floor","ceiling","wall","cabinets"}) : "Made of evergreen "
     "wood, this cabin looks rather sturdy, strong, and will protect well "
     "from the outside weather.",
     ({"table"}) : "The small table lies against the wall here. "
     "It appears to be small but can still seat about four to six people. "
     "The table has clutter and food on it in prepare for the next meal.",
     ]) );
  SetItemAdjectives( ([
     "walls" : ({"sturdy","strong"}),
     ]) );
  SetInventory( ([
     LAKE_NPC + "/wife" : 1,
     ]) );
  SetExits( ([
     "west" : LAKE_ROOM "/cabin_foyer",
     ]) );
}
