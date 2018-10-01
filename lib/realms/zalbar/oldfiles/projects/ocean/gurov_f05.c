#include <lib.h>
#include <domains.h>
#include "../forest.h"
inherit LIB_ROOM;

int PreventAnimals();

static void create() {
  ::create();
  SetShort("a thin trail into the forest");
  SetExits( ([
    "northwest" : FOREST_ROOM   "f04",
    ]) );
  AddExit("southeast", GUROV_VIRTUAL "gurovrd/0,2", (: PreventAnimals :) );
  AddExit("east",      GUROV_VIRTUAL "gurovrd/0,3", (: PreventAnimals :) );
  SetClimate("sub-arctic");  
  SetLong(
    "Directly to the southeast lies the Gurov Road, which leads north "
    "and south through the Principality of Gurov. Lying to the west is "
    "a small forest that seems to have been harvested lightly for wood. "
    "A thin splatter of trees extends out towards the road but has been "
    "cut back and not replanted over the years."
    );
  SetItems( ([
    "road" : "The road leads north and south through the Principality.",
    ({ "tree", "trees" }) : "The trees are mainly pines and other evergreens.",
    ]) );
  SetSmell("The scent of pine sap gives the forest an earthy smell.");
  SetListen("Animals chitter deep in the forest.");
  SetInventory( ([
    ]) );
}

int PreventAnimals() {
  if (this_player()->id("gurov_animal")) return 0;
  return 1;
}
