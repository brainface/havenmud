#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("first floor of the tower");
  SetLong("This is the entry to the tower.  The furnishings in this "
        "room leave something to be desired.  The room is very sparcely "
        "decorated.  The floor is uncovered and the walls are nothing "
        "more than bare, stone walls.  There is a storage room to the "
        "south, to the east is the exit and some stairs leading up into "
        "the tower.");
  SetItems( ([  ({"entry","room"}) : "This is a sparcely decorated room.  "
                "The floor and walls are both bare.",
        "tower" : "This is the first floor to the tower.",
        ({"furnishing","furnishings"}) : "There is not any furniture "
                "in this room.  The room is bare other than the "
                "floor and walls.",
        ({"floor","wall","walls"}) : "The floor and walls are cut from "
                "a cold and gray stone that was probaly cut in some mine "
                "by slaves miles away.  The only mystery is how much "
                "it actually took to build this tower.",
        ({"stairs","staircase"}) : "The bottom of the stairs can be seen "
                "from here.  They are cut from a gray stone and rise all "
                "the way around the tower until they are out of sight.",
        "stone" : "The stone everything is made of has been cut very "
                "smooth and appears to be fitted in a nice tight pattern "
                "in the stairs, walls, and floor.",
        ]) );
  SetItemAdjectives( ([ "room" : ({"sparcely","decorated"}),
        "wall" : ({"stone","gray","cold","bare","rock"}),
        "floor" : ({"stone","gray","cold","bare","rock"}),
        "stairs" : ({"stone","gray","cold","bare","rock"}),
        ]) );
  SetInventory( ([
        V_NPC + "manservant" : 1,
        ]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "This room in the tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "This room smells stale and unused." ]) );
  SetExits( ([ "south" : V_ROOM + "fl01s",
               "east" : V_ROOM + "fl01e" ]) );
}
