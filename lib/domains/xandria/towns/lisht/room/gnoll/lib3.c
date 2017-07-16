//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Hall of Necromancy");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetExits( ([
      "east" : "lib4",
      "down" : "lib1",
   ]) );
  SetLong(
    "This is the Hall of Necromancy, where those who wish to "
    "practice the dark, deadly magics come to train. There are "
    "no windows here, but light is provided by the copious oil "
    "lamps placed around the room. A well-made though gruesome "
    "tapestry hangs against one wall, but otherwise the room "
    "is empty and dreary. A staircase leads down and a small "
    "archway takes one eastward."
    );
  SetItems( ([
    ({ "lamps", "lamp" }) :
        "The lamps flicker ominously as you turn your attention "
        "toward them.",
    ({ "evoker", "evokers" }) :
        "You have a feeling you need to move east for that.",
    ({ "staircase", "stairs" }) :
        "A sturdy-looking staircase leads to the specialized halls. ",
    ({ "tapestry" }) :
        "The tapestry depicts the anatomy of a male elf, ribs pulled "
        "open to display his organs. It is very lifelike.",
    ({ "archway", "doorway", "arch", "door" }):
        "The small archway leads into another training room to the "
        "east.",
  ]) );
  SetItemAdjectives( ([
    "tapestry" : ({ "gruesome", "well-made" }),
    "lamps" : ({ "copious", "oil" }),
    "archway" : ({ "small"}),
  ]) );
  SetSmell( ([
    "default" : "There is a faint scent of decay.",
  ]) );
  SetListen( ([
    "default" : "It is all but silent here.",
   ]) );
  SetInventory( ([
    LISHT_NPC + "apophis" : 1,
   ]) );
}
