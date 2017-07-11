/*   Portia  1-9-99
   A hall in the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
 room::create();
  SetShort("a dim hallway");
  SetAmbientLight(20);
  SetClimate("indoors");
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "study2",
    "southwest" : MAL_ROOMS3 + "study1",
    ]) );
  SetListen( ([
    "default" : "A hushed conversation can be heard from the southwest.",
    ]) );
  SetSmell( ([
    "default" : "The smell of incense is abundant.",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("The hallway is very dimly lit here. Only two "
    "torches light the way along the curved walls that  "
    "form the Ring of Magic. This hallway seems to lead to the "
    "study rooms of the large place of learning. A small crack has "
    "formed in the western-most wall. It looks as though it was caused "
    "by years of exposure to moisture.");
  SetItems( ([
    ({"hallway"}) : (:GetLong:),
    ({"torches", "torch"}) : "The torches light the room dimly.",
    ({"crack"}) : "The crack seems to be due to moisture.",
    ({"walls", "wall"}) : "The obsidian walls curve to the southwest.",
    ]) );
  SetItemAdjectives( ([
    "hallway" : ({"dim", "lit", "dimly", "curved"}),
    "torches" : ({"two"}),
    "crack" : ({"small"}),
    "walls" : ({"western", "western-most", "most", "obsidian", "curved"}),
    ]) );
  }
