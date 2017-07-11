/*   Portia  12-11-98
     The general store.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("Malveillant General Store");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path9",
   ]) );
 SetInventory( ([
   MAL_NPC + "tom" : 1,
   MAL_NPC + "woman1" : 1,
   ]) );
 SetListen( ([
   "default" : "The room is very loud.",
   ]) );
 SetSmell( ([
   "default" : "There is an overwhelming scent of leather.",
   ]) );
 SetLong("This is the general store of Malveillant. "
   "It is owned by Tom Rifalia and his family since the "
   "time of the GodsWar. Tom takes great pride in making "
   "sure his shelves are stocked with the goods most desired "
   "by the people of Malveillant.");
 }

