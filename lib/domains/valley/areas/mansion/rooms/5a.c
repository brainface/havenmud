/* the kitchen
      kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an overly warm kitchen");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This kitchen is quite spacious and has many useful gadgets. "
         "The stoves are quite hot and it appears that there is enough "
         "food being prepared to feed many, many people. There are two "
         "small windows above the stove and a large swinging door that "
         "leads out to the dining room.");
  SetItems( ([
      ({ "warm kitchen", "kitchen" }) : 
	     "The kitchen is quite large and very warm.",
      ({ "useful gadgets", "gadgets", "gadget", "utensils", "utensil" }) :
		 "These are cooking utensils.",
      ({ "stoves", "stove" }) : "The stoves are quite large and very hot.",
      ({ "food" }) : "There is a tremendous amount of food here.",
      ({ "small windows", "windows", "window" }) : 
	     "The small windows let in a small amount of light.",
      ({ "door" }) : "The large door leads to the dining room.",
      ]) );
  SetItemAdjectives( ([
      "door" : ({"large", "swinging" }),
      "warm kitchen" : ({ "large", "spacious" }),
      "stoves" : ({"large", "hot"}),
             ]) );
  SetInventory( ([
        MANSION_NPC + "cook" : 1,
             ]) );
  SetExits( ([
          "east" : MANSION_ROOMS + "6a",
          ]) );
  SetListen( ([
        "default" : "The clattering of pots and pans can be heard.",
           ]) );
  SetSmell( ([
        "default" : "The room smells of good food.",
            ]) );
  }
