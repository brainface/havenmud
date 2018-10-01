//   Portia 12-11-98
//     The path to the general store.
//     version 2.0
// Quick Patch - This room will be completely redone with the addition of 
//   a Malv Academy in the future.
//   Aless 3/06

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
  
  SetShort("a muddy path");
  SetClimate("underground");
  SetExits( ([
     "south" : MAL_ROOMS + "center2",
     "east" : MAL_ROOMS + "path10",
     "west" : MAL_ROOMS + "path16",
     ]) );
  SetListen( ([
     "default" : "The area is quite loud.",
     ]) );
  SetSmell( ([
     "default" : "The area smells of leather and metal.",
     ]) );
  SetInventory( ([
     ]) );
  SetLong(
     "This path is quiet muddy and looks as though "
     "it is used very much. There are many footprints here "
     "that seem to go in all directions. Most of them however "
     "lead north towards a large building. This building is "
     "made of obsidian like all of the other buildings in "
     "Malveillant."
     );
  SetItems( ([
     ({"path"}) : (:GetLong:),
     ({"footprints", "footprint"}) : 
     	 "The footprints lead in all directions.",
     ({"building"}) : 
   	   "The large building looks empty. There is a sign nailed across the door.",
     ({"sign"}) :
   	   "The small sign gives notice that the general store has moved to the "
   	   "marketplace."
     ]) );
  SetItemAdjectives( ([
     "path" : ({"muddy", "used"}),
     "footprints" : ({"many"}),
     "building" : ({"large", "empty", "obsidian"}),
     "sign" : ({"small"}),
     ]) );
  SetEnters( ([
     ]) );
 }
