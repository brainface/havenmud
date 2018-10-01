#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetObviousExits("north");
  SetShort("the end of a path");
  SetLong("The path ends here in an area with a large tent nearby. "
          "The tent looks almost regal if that can be said about the "
          "home of a goblin, while the rest of the area seems "
          "to be nearly deserted.");
  SetSmell( ([
      "default" : "If possible, the smell seems worse here.",
     ]) );
  SetListen( ([
      "default" : "The sounds of business inundate the area.",
    ]) );
  SetItems( ([
    ({ "large tent", "tent" }) : "This tent seems somewhat important.",
    ]) );
  SetEnters( ([
      "large tent" : GOBLIN_TENT + "leader",
      ]) );
  SetExits( ([
     "north" : GOBLIN_ROOM + "m_4",
    ]) );
  SetInventory( ([
    GOBLIN_NPC + "little" : 5,
    ]) );
  }
