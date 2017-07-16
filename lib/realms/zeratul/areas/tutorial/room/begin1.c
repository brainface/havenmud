// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("at the beginning of a road");
  SetLong(
      "All around is a pine wood forest surrounded by towering cliffs of stone. "
      "There is a narrow path that leads to the north. A wall of thick bramble "
      "lines the edges of the path, preventing travel in any other directions. "
      "\nType <%^MAGENTA%^BOLD%^read book%^RESET%^> for instructions. "
  );
  SetInventory( ([
      T_OBJ + "info_book" : 1,
  ]) );
  SetItems( ([
      ({ "pine", "wood", "forest" }) : "The dense forest stretches in all directions.",
      ({ "rock", "face", "cliffs" }) : "The cliffs stretch vertically high into the sky.",
  ]) );
  SetSmell( ([
      "default" : "The strong smell of pine is present.",
  ]) );
  SetListen( ([
      "default" : "A gentle breeze is heard rustling through the trees.",
  ]) );
  SetExits( ([
      "north" : T_ROOM + "begin2.c"
  ]) );
}
