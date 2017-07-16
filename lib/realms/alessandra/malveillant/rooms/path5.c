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
   "north" : MAL_ROOMS + "center1",
   "east" : MAL_ROOMS + "path4",
   "west" : MAL_ROOMS + "path6",
   ]) );
 SetInventory( ([
   ]) );
 SetSmell( ([
   "default" : "The area smells earthen.",
   ]) );
 SetListen( ([
   "default" : "The sounds of civilization can be heard.",
   ]) );
 SetLong("This small path apparently leads to a "
   "dwelling of some kind. The building appears to "
   "be made of obsidian and very well taken care of. "
   "A soft coating of moss lines the path with an "
   "occasional small flower reaching towards the light.");
 SetItems( ([
   ({"path", "small path"}) : (:GetLong:),
   ({"dwelling", "building"}) : "The builidng is made of "
       "obsidian.",
   ({"coating", "moss"}) : "The moss is very soft.",
   ({"flower"}) : "The flower is very small.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"small", "lined"}),
   "dwelling" : ({"obsidian", "well", "taken care of"}),
   "coating" : ({"soft"}),
   "flower" : ({"occasional", "small", "very"}),
   ]) );
 SetEnters( ([
   "building" : MAL_ROOMS + "res4",
   ]) );
 }
