/* ballrooom part one
      kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a ballroom");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This ballroom is lavishly decorated and full of people. "
          "This end of the room seems to be the dance floor and a small "
          "string quartet is playing against the southern wall. The foyer "
          "is to the north and to the west lies a dining room. The ballroom "
          "continues on to the east.");
  SetItems( ([
       ({ "ballroom", "room" }) : (:GetLong:),
       ({ "decorations", "decoration" }) : 
	      "These decorations are hung quite nicely.",
       ({ "people", "person"}) : "These people seem quite happy and content.",
       ({ "string quartet", "quartet"}) : "The small quartet is quite skilled.",
       ({ "southern wall", "wall" }) : "The quartet is here.",
        ]) );
  SetExits( ([
       "east" : MANSION_ROOMS + "8a",
       "west" : MANSION_ROOMS + "6a",
       "north" : MANSION_ROOMS + "3a",
            ]) );
  SetInventory( ([
       MANSION_NPC + "young_woman" : 1,
       MANSION_NPC + "young_man" : 1
        ]) );
  SetSmell( ([
     "default" : "The smell of food drifts in from the west.",
         ]) );
  SetListen( ([
     "default" : "The string quartet is all that can be heard.",
        ]) );
  }
