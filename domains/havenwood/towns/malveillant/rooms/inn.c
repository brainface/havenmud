/*   Portia  12-11-98
     The inn in Malveillant
     version 2.0
     Edited by Alessandra v2.5 9/04
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 
  SetClimate("indoors");
  SetShort("a warm inn");
  SetLong(
     "This large inn is quite obviously a favored "
     "gathering spot in Malveillant. Large circular "
     "tables fill the center of the room with one "
     "rectangular table against the westernmost wall. "
     "The citizens of Malveillant seem to enjoy their "
     "time in this comfortable place. "
     "The inn's counter stands against the eastern wall "
     "next to an enormous stone fireplace. To the south "
     "the sounds of music and laughter are heard."
     );
  SetSmell( ([
     "default" : "The inn smells of fresh food.",
     ]) );
  SetListen( ([
     "default" : "The inn hums with conversation.",
     ]) );
  SetItems( ([
     ({"inn", "spot", "room", "spot", "center"}) : (:GetLong:),
     ({"tables", "table"}) : "The tables fill the room.",
     ({"wall", "walls"}) : "The walls are made of obsidian.",
     ({"citizens", "citizen"}) : "The citizens seem content here.",
     ({"counter"}) : "The large counter is to the east.",
     ({"fireplace"}) : "The fireplace is quite impressive.",
     ]) );
  SetItemAdjectives( ([
     "inn" : ({"gathering", "large", "favored"}),
     "tables" : ({"circular", "large", "rectangular"}),
     "wall" : ({"eastern", "western", "westernmost", "obsidian"}),
     "citizens" : "content",
     "counter" : ({"inn's", "large"}),
     "fireplace" : ({"enormous", "stone", "impressive"}),
     ]) );
  SetInventory( ([
     MAL_NPC + "paige" : 1,
     MAL_NPC + "equipper" : 1,
     MAL_NPC + "armour_equipper" : 1,
     ]) );
  SetNewsgroups( ({ "player.general" }) );   
  SetExits( ([
     "out" : MAL_ROOMS + "path12",
     "south" : MAL_ROOMS + "backroom",
     "up" : MAL_ROOMS + "sleep",
     ]) );   
}
