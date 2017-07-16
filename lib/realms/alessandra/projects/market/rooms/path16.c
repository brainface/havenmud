//   Portia 12-15-98
//     The path to the smithy.
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
     "south" : MAL_ROOMS + "path15",
     "east" : MAL_ROOMS + "path9",
     "southeast" : MAL_ROOMS + "center2",
     ]) );
  SetListen( ([
     "default" : "The sound of chatter can be heard "
       "from the north.",
     ]) );
  SetListen( ([
     "default" : "The air smells very earthen.",
     ]) );
  SetInventory( ([
     MAL_NPC + "citizen2" : 1,
     MAL_NPC + "man2" : 1,
     MAL_NPC + "woman2" : 1,
     ]) );
  SetLong(
     "This part of the path used to lead to the smithy "
     "of Malveillant. Currently the smithy is closed and there is a "
     "sign nailed to the door. The path is quite orderly and also seems "
     "to get a lot of traffic as there are footprints everywhere. "
     );
  SetItems( ([
     ({"path"}) : (:GetLong:),
     ({"footprints", "footprint"}) : 
   	   "There are too many footprints to count.",
     ({"smithy", "door"}) : 
   	   "The large smithy is boarded up, there is a sign on the door.",
     ({"sign"}) :
   	   "The small sign gives notice that the smithy has moved to the "
   	   "marketplace."
     ]) );
  SetItemAdjectives( ([
     "smithy" : ({"closed", "large"}),
     "sign" : ({"small"}),
     "path" : ({"orderly"}),
     ]) );
 SetEnters( ([
     ]) );

}
