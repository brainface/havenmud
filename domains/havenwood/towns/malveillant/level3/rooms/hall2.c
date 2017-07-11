/*   Portia  1-9-99
   A hall in the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a brightly lit hallway");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "evoker",
    "southwest" : MAL_ROOMS3 + "enchanter",
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The rooms smells of incense.",
    ]) );
  SetListen( ([
    "default" : "Chanting can be heard to the northeast.",
    ]) );
  SetLong("Not only does this room have three brightly lit "
    "torches, but there is a large window overlooking the "
    "courtyard of the Ring of Magic. The curved obsidian walls "
    "sparkle brightly in the light of the torches and the light "
    "coming from the windows of the other rooms of the large building.");
  SetItems( ([
    "room" : (:GetLong:),
    ({"torch", "torches"}) : "The torches are quite bright.",
    ({"window"}) : "The window overlooks the courtyard.",
    ({"walls", "wall" }) : "The walls shimmer in the light.",
    "light" : "The light shimmers on the walls.",
    ]) );
  SetItemAdjectives( ([
    "room" : ({"lit", "brightly"}),
    "torch" : ({"three", "brightly", "lit", "bright"}),
    "window" : "large",
    "light" : ({"bright", "shimmering"}),
    "walls" : ({"curved", "obsidian", "sparkling", "bright"}),
   ]) );
  }
