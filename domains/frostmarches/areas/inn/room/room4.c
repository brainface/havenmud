#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dark room");
  SetAmbientLight(25);
  SetLong("This is very obviously an \"economy\" class room.  The walls have "
          "no windows, there is no source of light, and there is no bed save "
          "for a small pad on the floor.  The room is very dark.  It might be "
          "difficult to stand this room for any length of time.");
  SetItems( ([ 
             ({ "dull walls", "windowsless walls", "walls", "wall" }) :
                "These are dull, windowless, walls.  The lack of light in "
                "the room makes them very hard to see.",
             ({ "small pad", "pad", "bed" }) :
                "This pad is about 2 inches thick, just enough to make the "
                "night bareable."
             ]) );
  SetSmell( ([
             "default" : "The scent of rat droppings can be detected."
             ]) );
  SetObviousExits("west");
  SetExits( ([ "west" : I_ROOM + "/hall2" ]) );
  SetClimate("indoors");
  SetInventory( ([ I_NPC + "/man" : 1 ]) );
}
