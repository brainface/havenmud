/*  Portia  12-7-98
    Path leading to the church.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a well-defined path");
 SetClimate("underground");
 SetExits( ([
   "north" : MAL_ROOMS + "path10",
   "south" : MAL_ROOMS + "path12",
   "west" : MAL_ROOMS + "center2",
   ]) );
 SetListen( ([
   "default" : "There is an eerie humm here.",
   ]) );
 SetSmell( ([
   "default" : "The area smells of incense and candles.",
   ]) );
 SetInventory( ([
   ]) );
 SetLong("This path is quite obviously very well maintained. "
   "A path of moss lines the way to the entranceway of the church. "
   "It continues in a ring encircling the center of town. To "
   "the east lies a huge church carved out of obsidian. It is "
     "dedicated to the savior of the dark-elves, Alessandra. A large "
   "wreath of black roses adorns the entranceway.");
 SetItems( ([
   ({"path", "area"}) : (:GetLong:),
   ({"moss", "path of moss"}) : "The moss lines the path.",
   ({"entranceway"}) : "The entranceway is adorned with a wreath.",
   ({"church"}) : "The obsidian church is incredibly beautiful.",
   ({"wreath", "roses", "rose"}) : "The black rose is the symbol "
       "of the Soirin faith.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"well-maintained", "well", "maintained"}),
   "church" : ({"huge", "obsidian", "incredibly", "beautiful"}),
   "wreath" : ({"black", "large"}),
   ]) );
 SetEnters( ([
   "church" : MAL_ROOMS + "church",
   ]) );
 }
