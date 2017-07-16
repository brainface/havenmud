/*  A food selling tent. */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetInventory( ([
    GOBLIN_NPC "cook" : 1,
  ]) );
  SetShort("inside a tent");
  SetObviousExits("out");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This tent serves the village as an inn. The obvious remains "
          "of many dinners litter the ground in a haphazard manner which "
          "suggests that the owner has no care for cleanliness. The oven "
          "in the middle of the tent is large enough to cook nearly "
          "anything.");
  SetSmell( ([
     "default" : "The oven smells like it has cooked "
                 "things that might not have been edible.",
    ]) );
  SetExits( ([
    "out" : GOBLIN_ROOM + "m_3",
  ]) );
}
