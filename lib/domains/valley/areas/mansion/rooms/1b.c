/* second floor guest bedroom
    kyla 7-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small bedroom");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40); 
  SetInventory( ([
       ]) );
  SetExits( ([
       "east" : MANSION_ROOMS + "2b",
         ]) );
  SetSmell( ([
      "default" : "The room smells of freshly cut flowers.",
         ]) );
  SetListen( ([
       "default" : "Voices can be heard outside the room.",
         ]) );
  SetLong("This room seems small when compared to the rest of the "
          "elaborate mansion. A large bed sits in the corner next to "
          "the window. A small table holds a vase of flowers, and the "
          "room appears to be being lived in temporarily.");
  SetItems( ([
      "room" : (:GetLong:),
      ({"large bed", "bed"}) : "The large bed looks soft and comfy.",
      "corner" : "The bed is pushed tightly into this corner.",
      "window" : "This window overlooks the north side of the mansion.",
      ({"small table", "table"}) : "The table is bare except for the vase.",
      "vase" : "The clear vase is full of flowers.",
      ({"flowers", "flower"}) : 
	    "The flowers are freshly cut and fill the room with their scent.",
      ]) );
  SetItemAdjectives( ([
     "large bed" : ({"soft", "comfy"}),
     "small table" : ({"small", "bare"}),
     "vase" : ({"clear"}),
     ]));
  }
