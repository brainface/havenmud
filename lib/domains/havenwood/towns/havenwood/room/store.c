#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetExits( ([
    "out" : HWD_ROOM "/gelf3",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a small general store");
  SetLong("This store, being set inside a tree, is not very large, "
    "but appears to stock just about everything one would need on a "
    "journey. The shop doesn't seem to have been here very long, "
    "and doesn't look as though it is frequented often at all. "
    "The shelves behind the counter are neverthelss quite full.");
  SetItems( ([
    ({"tree", "store", "shop"}) : (:GetLong :),
    ({"shelves", "shelf"}) : "The shelves are fully stocked.",
    ({"counter"}) : "The counter lines the southernmost part of the tree.",
    ]) );
  SetInventory( ([
    HWD_NPC "/merchant_trainer" : 1,
    HWD_NPC "/shopkeep" : 1,
    ]) );
  SetSmell( ([
    "default" : "The tree smells of sap and wood.",
    ]) );
  SetListen( ([
    "default" : "Birds can be heard singing from above.",
    ]) );
  }
