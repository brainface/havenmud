
/*   Portia  12-16-98
     Residance 5
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a beautiful home");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path7",
   ]) );
 SetInventory( ([
   MAL_NPC + "child" : 1,
   ]) );
 SetListen( ([
   "default" : "This home seems to be quite noisy.",
   ]) );
 SetSmell( ([
   "default" : "The scent of food is quite pleasant.",
   ]) );
 SetLong("This large home looks as though someone takes "
   "great pride in its care. The walls and windows sparkle "
   "as though they have been washed recently. A spotless "
   "table sits against the southernmost wall and a small "
   "crib has been place next to the door.");
 SetItems( ([
   "home" : (:GetLong:),
   ({"walls", "wall", "window", "windows"}) : "The walls "
       "and windows sparkle brightly.",
   ({"table"}) : "The table is clear of all dirt or dust.",
   ({"crib"}) : "This small crib seems to be placed here "
       "out of convienience.",
   "door" : "The large door swing with ease.",
   ]) );
 SetItemAdjectives( ([
   "home" : ({"beautiful", "large"}),
   "table" : "spotless",
   "crib" : "small",
   "door" : "large",
   ]) );
 }
