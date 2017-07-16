/*   Portia  12-11-98
     The path to the post office.
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
   "northeast" : MAL_ROOMS + "center2",
   "east" : MAL_ROOMS + "path13",
   "north" : MAL_ROOMS + "path15",
   ]) );
 SetListen( ([
   "default" : "The area is relatively quiet.",
   ]) );
 SetSmell( ([
   "default" : "The area smells very earthen.",
   ]) );
 SetInventory( ([
   MAL_NPC + "guard1" : 1,
   MAL_NPC + "guard2" : 1,
   ]) );
 SetLong("This dusty path leads to what appears to be "
   "some sort of official building. The path continues "
   "to the north and the east while a building lies "
   "to the south. The obsidian staircase in the center "
   "of town can be seen to the northeast, and there is "
   "what appears to be a row of official buildings to the "
   "east and south."
  );
 SetItems( ([
   ({"path", "dusty path", "area"}) : (:GetLong:),
   ({"building", "official building"}) : "The building seems "
       "rather important.",
   ({"staircase", "obsidian staircase"}) : "The staircase is to "
       "the northeast.",
   ({"row", "row of buildings", "buildings"}) :
       "These buildings are southeast of here.",
   ]) );
 SetEnters( ([
   "building" : MAL_ROOMS + "office",
    ]) );
 }
