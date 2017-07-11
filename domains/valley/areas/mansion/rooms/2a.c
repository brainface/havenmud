/* the foyer (w/stairs)
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a large foyer");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40); 
  SetLong(
    "The wooden bridge ends just north of here and open doors "
    "lead in to the foyer of a mansion. The large foyer is tiled in "
    "fine marble. The clean floor shines as the light from the overhead "
    "skylight hits it. A small table sits in the center of the foyer, supporting "
    "a vase of dried flowers. Corridors go east and west from here, leading "
    "to the rest of the mansion. To the north, beyond the doors, lies a bridge "
    "which connects to the surrounding grounds."
  );
  SetItems( ([
      ({ "large foyer", "foyer" }) : (:GetLong:),
      ({ "fine tile", "marble", "tile"}) : 
	     "The marble tiling is quite attractive and gives the room an elegant touch.",
      ({ "skylights", "skylight"}) : "The glass skylights shimmer in the light.",
      ({ "small table", "table" }) : 
	     "The small wooden table looks perfect with its burden of dried flowers.",
      ({ "flower", "flowers" }) : 
	     "These dried flowers are arranged in a delicate vase, which rests in "
		 "the middle of the small table.",
         "vase" : "This small white vase has various holes carved out of it, "
                  "forming an interesting pattern.",
         "floor" : "The marble shimmers in the light from the skylights.",
         "light" : "The light shines in through the skylights.",
       ]) );
  SetItemAdjectives( ([
           "small table" : ({"wooden"}),
          ]) );
  SetSmell( ([
      "default" : "The air smells like the room has jsut been cleaned.",
         ]) );
  SetListen( ([
      "default" : "There is music coming from the other side of the house.",
             ]) );
  SetExits( ([
      "north" : MANSION_ROOMS + "bridge",
      "east" : MANSION_ROOMS + "3a",
      "west" : MANSION_ROOMS + "1a",
          ]) );
  SetInventory( ([
         MANSION_NPC + "maid1" : 1,
          ]) );
  }
