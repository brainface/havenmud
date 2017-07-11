#include <lib.h>
#include "../wood.h"
#define ROAD "/domains/havenwood/virtual/havenwoodroad/155,155"
#define ARIKA_ROOM  "/domains/havenwood/areas/glen/rooms/path1"
inherit LIB_ROOM;

static void create() {
  room::create();
   SetDomain("HavenWood");
  SetShort("on the fringes of the HavenWood");
  SetLong("This large forest is full of colorful trees that seem to "
    "welcome travellers. The road continues to the west and leads back to "
    "the main road to the east. The large branches which stem off "
    "from the trees seem quite forbiding. There seems to be an aura of "
    "uncertainty here as the large trees block a majority of the "
    "sunlight during the day.");
  SetItems( ([
     ({ "tree", "trees", "bough", "boughs" }) :
    "The trees seem to have a life of their own.",
     ]) );
  SetExits( ([
     "west" : ROAD,
     "northeast" : HWD_ROOM + "/wood3",
     "east": ARIKA_ROOM,
          ]) );
 }
