// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("within a small meadow in a forest");
  SetLong(
      "All around is a pine wood forest surrounded by towering cliffs of stone. "
      "There is a narrow path that leads to a small meadow. A large bed of flowers "
      "blankets the field like a thick carpet of colors. "
      "The path continues to the north back into the thicket of bramble. "
      "\nType <%^MAGENTA%^BOLD%^smell flowers%^RESET%^> to smell the flowers. "
  );
  SetItems( ([
      ({ "pine", "wood", "forest" }) : "The dense forest stretches in all directions.",
      ({ "rock", "face", "cliffs" }) : "The cliffs stretch vertically high into the sky.",
      ({ "flowers", "flower" }) : "The bed of flowers is vibrant with red and orange.",
  ]) );
  SetSmell( ([
      "default" : "The strong smell of pine is present.",
      "flowers" : "The sweet floral scent permeates your senses. ",
  ]) );
  SetListen( ([
      "default" : "A gentle breeze is heard rustling through the trees.",
  ]) );
  SetExits( ([
      "north" : T_ROOM + "begin3.c",
      "south" : T_ROOM + "begin1.c",
  ]) );
}
