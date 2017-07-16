#include <lib.h>
inherit LIB_ROOM;
#define OUT "/domains/westwood/virtual/soleilroad/0,2"
#include "../hospital.h"

static void create() {
   room::create();
   SetDomain("WestWood");
   SetShort("in front of the Eclat Hospital");
   SetLong("The Eclat Hospital is to the west; the two story "
           "building is white and plain, but it looks like it "
           "serves many different types of individuals inside.  "
           "A path goes off back to the main trail to the east, and "
           "there is a door in the hospital leading in.");
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
           ]) );
   SetItemAdjectives( ([
                         "hospital" : ({ "eclat","two story",
                                         "white","plain","clean" }),
                         "building" : ({ "eclat","two story",
                                         "white","plain","clean" }),
                    ]) );
   SetExits( ([
                "east" : OUT,
           ]) );
   AddEnter("hospital",H_ROOM + "waiting");
   SetDoor("hospital",H_ROOM + "door");
}
