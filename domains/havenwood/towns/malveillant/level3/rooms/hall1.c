/*   Portia  1-9-99
   A hall in the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dark hallway");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "southeast" : MAL_ROOMS3 + "evoker",
    "northwest" : MAL_ROOMS3 + "necromancer",
    ]) );
  SetListen( ([
    "default" : "There is chanting to the south of here.",
    ]) );
  SetSmell( ([
    "default" : "There is a foul smell coming from the north.",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("This hallway seems to have an especially dim torch. "
    "There are no windows and no light is escaping from either of the "
    "two workrooms this hallway leads to. Some cobwebs are stuck to the "
    "curved obsidian walls and there seems to be a crack that runs "
    "along the floor.");
    SetItems( ([
      "floor" : "The obsidian floor is quite smooth.",
      "crack" : "The crack is quite small.",
      "hallway" : (:GetLong:),
      "torch" : "The torch is quite dim.",
      ({"walls", "wall"}) : "The walls are curved to the southwest.",
      ({"cobwebs", "cobweb"}) : "The cobwebs line the walls.",
    ]) );
  SetItemAdjectives( ([
    "hallway" : ({"dark"}),
    "walls" : ({"curved", "obsidian"}),
    "crack" : ({"small"}),
    "floor" : "obsidian",
    ]) );
  }
