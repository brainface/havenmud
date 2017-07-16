/*   Portia  12-11-98
     The path to Residences.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a small path");
 SetClimate("underground");
 SetExits( ([
   "south" : MAL_ROOMS + "center1",
   "west" : MAL_ROOMS + "path8",
   "east" : MAL_ROOMS + "path2",
   ]) );
 SetInventory( ([
   ]) );
 SetSmell( ([
   "default" : "The area smells earthen.",
   ]) );
 SetListen( ([
   "default" : "The sounds of civilization can be heard.",
   ]) );
 SetLong("This is a small path at the north end of the"
         " cave. There is little here except a soft coating"
         " of moss that lines the path  with an occasional"
         " small flower reaching towards the light.");
 SetItems( ([
   ({"path", "small path"}) : (:GetLong:),
   ({"dwelling", "building"}) : "The building is made of "
       "obsidian.",
   ({"coating", "moss"}) : "The moss is very soft.",
   ({"flower"}) : "The flower is very small.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"small", "lined"}),
   "coating" : ({"soft"}),
   "flower" : ({"occasional", "small", "very"}),
   ]) );
 SetEnters( ([
   ]) );
 }
