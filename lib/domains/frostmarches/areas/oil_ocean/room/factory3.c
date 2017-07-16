//Illura@haven
//factory3
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside a factory");
  SetLong(
    "This part of the factory holds an enormous furnace, "
    "filled to the brim with bitumen and oil being melted and "
    "processed. The resulting products are poured nearby "
    "into waiting clay jars loaded in carts. A pair of smokestacks "
   "lead upward, forcing some of the black smog out, and "
   "a shaky staircase leads back down."
  );
  SetExits( ([
    "down" : OIL_ROOM "/factory1"
  ]) );
  SetItems( ([
    ({"furnace"}) : "The giant furnace turns the raw oil into sparkling black pitch with intense heat.",
    ({"bitumen", "oil"}) : "The buckets of oil and bitumen are hoisted into the furnace before descending back to the lower floors of the factory.",
    ({"products", "product", "jars", "jar"}) : "The jars of pitch are numerous.",
    ({"carts", "cart"}) : "There are many rickety old carts here, designed to push the jars of pitch to wherever they are headed.",
    ({"smokestacks", "smokestack"}) : "Twin smokestacks, too narrow to climb, help push some of the smoke out of the factory.",
    ({"smog"}) : "The smog is heavy and laden with dangerous fumes.",
    ({"staircase"}) : "The staircase is the only way out of here."
  ]) );
  SetItemAdjectives( ([
    "furnace" : ({"enormous"}),
    "products" : ({"resulting", "clay"}),
    "smog" : "black",
    "staircase" : "shaky"
  ]) );
  SetInventory( ([
    OIL_NPC + "worker" : 3,
    OIL_NPC + "taskmaster" : 1,
  ]) );
  SetListen( ([
    "default" : "There is a buzz of activity here.",
  ]) );
  SetSmell( ([
    "default" : "Black smoke fills the air no matter where you turn in this factory.",
  ]) );
}
