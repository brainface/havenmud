#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
  room::create();
  
  SetShort("a section or tunnel");
  SetLong("This section of tunnel is very dark and empty.  Nothing "
    "appears to of entered this tunnel in ages as dust has settled "
    "over everything.  The walls and floor slightly dampened from "
    "moisture in the air.  There exits to the south and east.");
  SetItems( ([
    ({"tunnel"}) : (:GetLong:),
    ({"dust"}) : "The dust is laid thickly over the floor in this "
      "section of cave.",
    ({"wall","walls","floor"}) : "The walls and floor here appear to "
      "damp from moisture in the air.  They are natural and have never "
      "touched by living hands.",
    ({"air","moisture"}) : "The air is thick with moisture.",
  ]) );
  SetItemAdjectives( ([
    "tunnel" : ({"dark","empty"}),
    "wall" : ({"damp","dampened"}),
  ]) );
  SetExits( ([
    "north" : R_ROOM + "lair5",
    "northwest" : R_ROOM + "lair7",
  ]) );
  SetInventory( ([
    R_NPC + "lost_lady" : 1,
  ]) );
  SetAmbientLight(0);
  SetClimate("indoors");
  SetSmell( ([
    "default" : "The room smells of moisture and mold.",
  ]) );
  SetListen( ([
    "default" : "Small echos of squeaks fill the room.",
  ]) );
}
