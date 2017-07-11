
/* A room in the kingdom
   Elasandria 4/13/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hushed clearing");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetLong(
    "The trees become less dense through here. A few hardy toadstools "
    "and numerous ferns cover the forest floor. The impenetrable "
    "growth surrounding the clearing seems to constantly shift."
  );
  SetItems( ([
    ({ "growth", "tree", "trees", "greenery", "forest"}) : "The "
      "trees seem to form a luxurient wall of greenery to protect this quiet "
      "clearing.",
    ({ "mushroom", "mushrooms", "toadstool", "toadstools"}) :
      "The mushrooms are unnaturally large and vividly colored.",
    ({ "plant", "plants", "fern", "ferns"}) : "These plants "
      "are very lush and green.",
    ({ "quiet clearing", "clearing", "area"}) : "This quiet little "
      "clearing is seemingly guarded by the forest.",
    "floor" : "The forest floor is slightly damp.",
  ]) );
  SetItemAdjectives( ([
    "growth" : ({ "dense" }),
    "plant" : ({ "lush", "green", }),
    "mushroom" : ({ "large", "vividly", "colored" }),
    "dense growth" : "impenetrable",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "It is utterly silent in the clearing.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "stag" : 1,
  ]) );
  SetExits( ([
    "east" : KINGDOM_ROOMS + "kingdom17",
  ]) );
}
