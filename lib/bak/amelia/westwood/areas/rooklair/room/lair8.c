#include <lib.h>
#include "../rook.h"

inherit LIB_FISHING;
 
static void create() {
  fishing::create();
  SetDomain("WestWood");
  SetShort("an underground river");
  SetLong("Roaring through this room is a large river.  It careens "
    "though the room along the southern wall coming in one side of "
    "and escaping out the other.  The room is dimly lit "
    "by small amounts of moss that seems to contain a bit of "
    "phosphorous.  The temperature here is slightly warmer than "
    "the rest of the cave and the humidity here is sweltering.  "
    "The tunnel leads out to the north and a small rope dangles in "
    "from an opening in the ceiling.");
  SetItems( ([
    ({"room","cave"}) : (:GetLong:),
    ({"wall","walls"}) : "The walls here shimmer from the light and "
      "small amounts of water slide down in drops.",
    ({"tunnel"}) : "There is a tunnel leading north from here.",
    ({"opening","ceiling"}) : "There is an opening leading up through "
      "the ceiling.  A small rope dangles in from above.",
    ({"rope"}) : "This rope appears to be made of a silk.  It is smooth "
     "and just dangles down through the opening of the chasm.",
    ({"river"}) : "The river is large and runs along the wall from one "
      "end of the room to the other.  The water is clear and pure.",
  ]) );
  SetItemAdjectives( ([
    "room" : ({"dim","dimly","lit","sweltering","humid"}),
    "rope" : ({"small","silk","smooth","dangling"}),
    "river" : ({"large","roaring"}),
  ]) );
  SetExits( ([
    "north" : R_ROOM + "lair9",
  ]) );
  SetClimate("indoors");
  SetInventory( ([
    R_OBJ + "rope4" : 1,
    R_OBJ + "river" : 1,
    R_OBJ + "moss" : 2,
  ]) );
  SetSmell( ([
    "default" : "This room smells of fish and water.",
  ]) );
  SetListen( ([
    "default" : "The roaring of the river is deafening..",
  ]) );
  SetChance(45);
  SetSpeed(5);
  SetMaxFishing(35);
  SetFish( ([
    R_NPC + "d_shark" : 25,
    R_NPC + "d_turtle" : 35,
    R_NPC + "d_snake" : 15,
    R_NPC + "d_fish" : 75,
  ]) );
}
