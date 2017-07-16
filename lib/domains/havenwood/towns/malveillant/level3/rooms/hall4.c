/*   Portia  1-9-99
   A hall in the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dank hallway");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northwest" : MAL_ROOMS3 + "study1",
    "southeast" : MAL_ROOMS3 + "diviner",
    ]) );
  SetInventory( ([
    ]) );
  SetListen( ([
    "default" : "Soft chanting can be heard to the southeast.",
    ]) );
  SetSmell( ([
    "default" : "The air smells musty here.",
    ]) );
  SetLong("This dank hallway is rather small. A few torches line "
         "the walls along with the occasional spiderweb. The walls "
        "seem moist as if there may be a crack in the strong obsidian. "
        "The walls both curve in a sort of northeast direction. "
        "The floor feels gritty and upon closer inspection one can see "
       "that there is a light coating of sand here.");
  SetItems( ([
    ({"hallway"}) : (: GetLong :),
    ({"torches", "torch" }) : "The torches give off little light.",
    ({"spiderwebs", "spiderweb"}) : "The spiderwebs are rather large.",
    ({"walls", "wall"}) : "The curved obsidian walls are quite moist.",
    ({"floor"}) : "The floor is covered in sand.",
    ({"sand"}) : "The sand is a light dusting over the floor.",
    ]) );
  SetItemAdjectives( ([
    "hallway" : ({"dank", "small"}),
    "torches" : ({"few"}),
    "spiderwebs" : ({"large", "occasional"}),
    "walls" : ({"curved", "moist", "obsidian"}),
    "floor" : "gritty",
    "sand" : "light",
    ]) );
  }
