//   Portia 12-15-98
//     The path to the armoury.
//     version 2.0
// Quick Patch - This room will be completely redone with the addition of 
//   a Malv Academy in the future.
//   Aless 3/06

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();

 SetShort("a busy path");
 SetClimate("underground");
 SetExits( ([
   "south" : MAL_ROOMS + "path11",
   "west" : MAL_ROOMS + "path9",
   "southwest" : MAL_ROOMS + "center2",
   ]) );
 SetListen( ([
   "default" : "The sound of chatter can be heard "
       "from the north.",
   ]) );
 SetListen( ([
   "default" : "The air smells very earthen.",
   ]) );
 SetInventory( ([
   MAL_NPC + "citizen1" : 1,
   MAL_NPC + "man1" : 1,
   ]) );
 SetLong(
     "This part of the path used to lead to the armoury "
     "of Malveillant. Currently the armoury is closed and there is a "
     "sign nailed to the door. The path is quite orderly and also seems "
     "to get a lot of traffic as there are footprints everywhere. "
     );
  SetItems( ([
     ({"path"}) : (:GetLong:),
     ({"footprints", "footprint"}) : 
   	   "There are too many footprints to count.",
     ({"armoury", "door"}) : 
   	   "The large armoury is boarded up, there is a sign on the door.",
     ({"sign"}) :
   	   "The small sign gives notice that the armoury has moved to the "
   	   "marketplace."
     ]) );
  SetItemAdjectives( ([
     "armoury" : ({"closed", "large"}),
     "sign" : ({"small"}),
     "path" : ({"orderly"}),
     ]) );
  SetEnters( ([
     ]) );
 }
