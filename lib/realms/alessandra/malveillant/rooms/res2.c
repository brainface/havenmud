/*  Portia  12-12-98
    Residance 2.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a small home");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path2",
   ]) );
 SetInventory( ([
   MAL_NPC + "woman2" : 1,
   ]) );
 SetListen( ([
   "default" : "The home is very quiet.",
   ]) );
 SetSmell( ([
   "default" : "The house smells of food.",
   ]) );
 SetLong("This small home seems to be quite run down. "
   "Cobwebs cover the door and the windows. What "
   "furniture there is seems to be very old, dating "
   "almost all the way back to the GodsWar. A thick "
   "coating of dust covers the floor and a soft layer "
   "of moss is underfoot as well.");
 SetItems( ([
   ({"house", "home"}) : (:GetLong:),
   ({"cobwebs", "cobweb"}) : "The cobwebs seem very old.",
   ({"door", "windows", "window"}) : "The windows and "
       "door are covered in cobwebs.",
   ({"furniture"}) : "The furniture is almost ancient.",
   ({"coating", "dust", "floor", "moss", "layer"}) :
       "The moss and dust cover the floor.",
   ]) );
 SetItemAdjectives( ([
   "house" : ({"small", "run down"}),
   "cobwebs" : ({"old"}),
   "door" : ({"covered"}),
   "furniture" : ({"old", "very", "almost", "ancient"}),
   "coating" : ({"thick", "soft"}),
   ]) );
 }
