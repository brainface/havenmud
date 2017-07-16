/*   Portia 12-15-98
     The path to Res5.c
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a dusty path");
 SetClimate("underground");
 SetExits( ([
   "northeast" : MAL_ROOMS + "center1",
   "north" : MAL_ROOMS + "path7",
   "east" : MAL_ROOMS + "path5",
   ]) );
 SetListen( ([
   "default" : "The air is still here.",
   ]) );
 SetSmell( ([
   "default" : "The air smells earthen.",
   ]) );
 SetInventory( ([
   MAL_NPC + "citizen2" : 1,
   ]) );
 SetLong("This path is relatively plain. "
   "There seems to be only dust in this part "
   "of the town and nothing grows here. It "
   "is almost as though nothing can exist in this "
   "immediate area, as a slight breeze wipes away "
   "any footprints that might be made by passersby. "
   "A small building lies to the south.");
 SetItems( ([
   ({"path", "area"}) : (:GetLong:),
   "dust" : "The dust is thick yet powdery to the touch.",
   "building" : "This building looks like a home of some kind.",
   ]) );
 SetItemAdjectives( ([
   "path" : "dusty",
   "dust" : ({"thick", "powdery"}),
   "building" : "small",
   ]) );
 SetEnters( ([
   "building" : MAL_ROOMS + "res5",
   ]) );
 }
