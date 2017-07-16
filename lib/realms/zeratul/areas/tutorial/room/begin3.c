// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("at the end of a road");
  SetLong(
      "All around is a pine wood forest surrounded by towering cliffs of stone. "
      "There is a narrow path that leads to the south. A wall of thick bramble "
      "ends here, revealing a large tavern at the end of the road. "
      "\nType <%^MAGENTA%^BOLD%^enter tavern%^RESET%^> to enter the building. "
  );
  SetItems( ([
      ({ "pine", "wood", "forest" }) : "The dense forest stretches in all directions.",
      ({ "rock", "face", "cliffs" }) : "The cliffs stretch vertically high into the sky.",
      ({ "tavern", "pub", "building" }) : "This building is structure made of wood.",
  ]) );
  SetSmell( ([
      "default" : "The strong smell of pine is present.",
  ]) );
  SetListen( ([
      "default" : "A gentle breeze is heard rustling through the trees.",
  ]) );
  SetEnters( ([
      "tavern" : T_ROOM + "tavern1",
  ]) );
  SetExits( ([
      "south" : T_ROOM + "begin2.c",
  ]) );
}
