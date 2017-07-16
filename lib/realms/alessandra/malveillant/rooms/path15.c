/*   Portia   12-11-98
     The path to the hall of defense.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a stony path");
 SetClimate("underground");
 SetExits( ([
   "east" : MAL_ROOMS + "center2",
   "north" : MAL_ROOMS + "path16",
   "south" : MAL_ROOMS + "path14",
   ]) );
 SetListen( ([
   "default" : "The sound of metal hitting metal is all "
       "that can be heard.",
   ]) );
 SetSmell( ([
   "default" : "The area smells very earthen.",
   ]) );
 SetInventory( ([
   MAL_NPC + "guard1" : 1,
   ]) );
 SetLong("This path is very uncomfortable to walk down. "
   "Its large numbers of stones makes it quite hard on "
   "one's feet. From here one can see the center of town "
   "to the east and the town's Hall of Defense to the west. "
   "The path continues farther to the south.");
 SetItems( ([
   "path" : (:GetLong:),
   ({"stones", "stone"}) : "There are quite a few large stones here.",
   ({"hall", "hall of defense"}) : "The Hall of Defense is "
       "responsible for training the Royal Guard.",
   ]) );
 SetItemAdjectives( ([
   "path" : "stony",
   "stones" : "large",
   ]) );
 SetEnters( ([
   "hall" : MAL_ROOMS + "defense",
   ]) );
 }
