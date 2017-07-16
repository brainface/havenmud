//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Hall of Evokation");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetExits( ([
      "west" : "lib3",
      "down" : "lib2",
   ]) );
  SetLong(
    "This is the Hall of Evokation, where students of the magical "
    "arts come to receive their training. There are few windows "
    "here, and they are all small. Light is provided by the many "
    "oil lamps placed around the room. There almost seems to be "
    "an aura of mystery about this place. A staircase leads down, "
    "and a small archway leads west."
    );
  SetItems( ([
    ({ "lamps", "lamp", "window", "windows" }) :
        "The lamps cast a soft glow on the shadows where the "
        "light from the windows does not reach.",
    ({ "necromancer", "necromancers" }) :
        "You have a feeling you need to move west for that.",
    ({ "aura" }) :
        "The mysterious aura cannot be seen, but it prickles the skin. ",
    ({ "staircase", "stairs" }) :
        "A sturdy-looking staircase leads to the specialized halls. ",
  ]) );
  SetItemAdjectives( ([
    "window" : ({ "rose", "rose-colored", "small" }),
    "lamp" : ({ "oil" }),
    "window" : ({ "small" }),
  ]) );
  SetSmell( ([
    "default" : "There is a faint aroma of singed flesh.",
  ]) );
  SetListen( ([
    "default" : "It is all but silent here. ",
   ]) );
  SetInventory( ([
    LISHT_NPC + "sekhemre" : 1,
   ]) );
}
