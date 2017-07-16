#include <lib.h>

inherit LIB_ROOM;
#define OUT "/domains/westwood/virtual/westwood/"
#include "../westwood.h"
#define H_ROOM WESTWOOD_DIR + "/areas/hospital/room/"

static void create() {
   int x, y;
   x = 17;
   y = 15;
   room::create();
   SetDomain("WestWood");
   SetShort("in front of the Eclat Hospital");
   SetLong("The Eclat Hospital is to the west; the two story "
           "building is white and plain, but it looks like it "
           "serves many different types of individuals inside.  "
           "The Soleil Road travels north and south along a "
	"fence, and "
           "there is a door in the hospital leading in.  The "
	"Westwood spreads out to the east, northeast, and "
	"southeast.");
   SetItems( ([
                ({ "main trail","path","trail" }) :
                   "The main trail is off to the east.",
                ({ "hospital" }) :
                   "The Eclat Hospital is two stories tall, and "
                   "a door leads inside here.  It is plain and "
                   "white and very clean looking, but it is "
                   "used by many.",
                ({ "Eclat Hospital","building" }) :
                   "The Eclat Hospital is two stories tall, and "
                   "a door leads inside here.  It is plain and "
                   "white and very clean looking, but it is "
                   "used by many.",
		({ "soleil road","road" }) :
		"The road travels north and south.",
		({ "fence" }) :
			"The fence blocks travel to the west, "
			"but there is an opening to allow "
			"entrance through the hospital door.",
           ]) );
   SetItemAdjectives( ([
                         "hospital" : ({ "eclat","two story",
                                         "white","plain","clean" }),
                         "building" : ({ "eclat","two story",
                                         "white","plain","clean" }),
                    ]) );
   SetExits( ([
                "east" : OUT + (x+1) + "," + (y),
		"north" : OUT + (x) + "," + (y + 1),
		"south" : OUT +(x) + "," + (y - 1),
		"northeast" : OUT + (x - 1) + "," + (y + 1),
		"southeast" : OUT  + (x + 1) + "," + (y - 1),
           ]) );
   AddEnter("hospital",H_ROOM + "waiting");
   SetDoor("hospital",H_ROOM + "door");
}
