#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a second floor hallway");
  SetExits( ([
    "east"  : "2-6",
    "south" : "2-4",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("The hallway curves back to the south and east from here. "
          "To the south, the hallway curves along the outer walls of "
          "the tower, leading to the far side. To the east the hallway "
          "leads toward the center of the tower with its obsidian "
          "stairwell. The walls of the second floor seem to be made of "
          "a smoother stone which meshes very well.");
  SetItems( ([
    ({ "wall", "walls", "stone" }) : "The walls of the second floor "
         "are much more well crafted than those of the first.",
    ]) );
  SetSmell( ([
    "default" : "There is no unusual scent in the air.",
    ]) );
  SetListen( ([
    "default" : "A quiet slurping noise comes from the south.",
    ]) );
}
