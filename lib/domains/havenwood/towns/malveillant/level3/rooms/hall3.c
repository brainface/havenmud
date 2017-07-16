/*   Portia  1-9-99
   A hall in the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dusty hallway");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northwest" : MAL_ROOMS3 + "diviner",
    "northeast" : MAL_ROOMS3 + "enchanter",
    ]) );
  SetInventory( ([
    ]) );
  SetListen( ([
    "default" : "Soft sounds can be heard in the distance.",
    ]) );
  SetSmell( ([
    "default" : "The area smells of mildew and incense.",
    ]) );
  SetLong("The walls of this small hallway curve "
    "northward towards the entranceway. There are "
    "several cobwebs here and it is obvious noone has "
    "dusted here in a very long time. Several small "
    "torches line the curved walls and give everything a "
    "faint shimmer. Several small stones scatter the "
    "hallway. They seem as if someone dropped them here "
    "on purpose.");
  SetItems( ([
    ({"hallway"}) : (:GetLong:),
    ({"walls", "wall"}) : "The curved walls lead north.",
    ({"stones", "stone"}) : "The stones seem to be "
        "left here on purpose.",
    ({"cobwebs", "cobweb"}) : "The stringy cobwebs hang off "
        "the small torches.",
    ({"torches", "torch"}) : "The torches light the room.",
    ]) );
  SetItemAdjectives( ([
    "hallway" : "small",
    "walls" : "curved",
    "torches" : "small",
    "stones" : ({"several", "small"}),
    ]) );
  }
