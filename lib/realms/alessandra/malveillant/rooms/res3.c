
/*   Portia  12-15-98
     Residence 7
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a familiar home");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path2",
   ]) );
 SetListen( ([
   "default" : "The area is very quiet.",
   ]) );
 SetSmell( ([
   "default" : "The area smells of earth.",
   ]) );
 SetInventory( ([
   ]) );
 SetLong("This home looks quite familiar. "
   "It is decorated very sparsely with only "
   "one large chair near a huge stone fireplace. "
   "The only other decor is a large hand-woven "
   "rug covering the floor. Its obsidian walls are "
   "bare and there is no other furniture.");
 SetItems( ([
   "home" : (:GetLong:),
   ({"furniture", "chair"}) : "The large chair is the only furniture.",
   ({"fireplace"}) : "The fireplace is very large.",
   ({"rug", "floor"}) : "The cold floor is covered with "
       "a fine rug.",
   ({"walls", "wall"}) : "The walls are bare.",
   ]) );
 SetItemAdjectives( ([
   "home" : "familiar",
   "furniture" : ({"large", "one", "only"}),
   "fireplace" : ({"huge", "stone", "very", "large"}),
   "rug" : ({"cold", "hand-woven", "fine", "large"}),
   "walls" : ({"bare", "obsidian"}),
   ]) );
 }
