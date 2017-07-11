
/* a room in the kingdom
   Elasandria 4/15/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a clearing");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetLong(
    "The trees become less dense through here. A few hardy toadstools "
    "and numerous ferns blanket the forest floor. An ancient, majestic "
    "oak dominates the area. The surrounding forest appears to shift "
    "constantly."
  );
  SetItems( ([
    ({"growth","tree","trees"}) : "The trees are obviously ancient due "
      "to their impressive size.",
    ({"hardy toadstool","toadstool","toadstools","mushroom","mushrooms"})
      : "The mushrooms are unnaturally large and vividly colored.",
    ({"lush plant","plant","plants","fern","ferns"}) : "These plants "
      "are unnaturally large and vividly colored.",
    ({"area","clearing"}) : "The clearing is serene and peaceful.",
      "floor" : "The forest floor is slightly damp.",
    ({"ancient oak","oak"}) : "The sheer size and circumference of this "
      "oak is mind boggling. Soft moss surrounds a tent-like opening in the "
      "trunk.",
    ({"soft moss","moss"}) : "Soft, spongy moss in various shades of "
      "greens frames the opening in the oak",
    ({"large opening","opening","trunk"}) : "A large opening in the trunk "
      "of the oak looks dark and mysterious.",
  ]) );
  SetItemAdjectives( ([
    "large opening" : ({"dark","mysterious","tent-like"}),
    "soft moss" : "spongy",
    "lush plant" : ({"large","numerous"}),
    "hardy toadstool" : "large",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The faint sound of music and laughter can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "guard1" : 1,
    KINGDOM_NPC + "guard2" : 1,
  ]) );
  SetEnters( ([
    "ancient oak" : KINGDOM_ROOMS + "kingdom12",
  ]) );
  SetExits( ([
    "northwest" : KINGDOM_ROOMS + "kingdom7",
    "southwest" : KINGDOM_ROOMS + "kingdom17",
    "southeast" : KINGDOM_ROOMS + "kingdom19",
    "north" : KINGDOM_ROOMS + "kingdom8",
    "south" : KINGDOM_ROOMS + "kingdom18",
    "east" : KINGDOM_ROOMS + "kingdom14",
   ]) );
}
