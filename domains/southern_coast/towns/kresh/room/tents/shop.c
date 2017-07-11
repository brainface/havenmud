/*  A shop */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside a tent");
  SetObviousExits("out");
  SetExits( ([
      "out" : GOBLIN_ROOM + "e_1",
      ]) );
  SetLong("This tent it home to the local barterer. His trade takes him "
          "across the world looking for better prices on items. When he "
          "is here, he is known as a shrewd dealer.");
  SetSmell( ([
     "default" : "The tent smells of various types of merchandise.",
    ]) );
  SetAmbientLight(40);
  SetInventory( ([
    GOBLIN_NPC + "shopkeep" : 1,
      ]) );
  }
