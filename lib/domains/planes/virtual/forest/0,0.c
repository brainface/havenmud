/* A base room to be able to leave. */
#include <lib.h>
#include <domains.h>
#include "../../planes.h"
inherit DIR_VIRT + "forest.c";

int PreHole(string);

static void create() {
  forest::create(0,0);
  SetItems( ([
     "mist" : "A fine mist covers the ground, spewing from a hole "
              "in the land.",
     "hole" : "The hole seems to lead endlessly downward.",
   ]) );
  SetLong(GetLong() + "There is a large hole in the ground with "
         "mist pouring out.");
  SetProperty("lower plane",1);
  AddEnter("hole", HAVENWOOD_AREAS+"wood/rooms/wood1", (: PreHole :) );
  AddInventory(PLANE_OBJ + "sign_forest",1);
 }

int PreHole(string dir) {
  return userp(this_player());
  }
