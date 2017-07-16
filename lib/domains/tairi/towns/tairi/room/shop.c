#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a reinforced building");
  SetExits( ([
    "out" : "path9",
    ]) );
  SetClimate("indoors");
  SetLong("This building houses the local shop. Scattered around the "
          "room are examples of the goods the shopkeep often sells. "
          "The walls here are made of a more reinforced wood, rather "
          "than the traditional buildings in town.");
  SetItems( ([
     ({ "building", "room", "shop", "house"}) :
     	  (: GetLong :),
     ({ "goods", "examples" }) :
        "These seem to be protected by some magic to make them unstealable.",
     ({ "wall", "walls" }) :
     	  "The walls of this non-traditional building is made from "
     	  "reinforced wood.",
     ({ "town", "tairi" }) :
     	  "The town of Tairi can be seen out the door.", 
    ]) );
  SetItemAdjectives( ([
     "building" : ({ "local", "wooden", "wood", "non-traditional",
     								 "nontraditional" }),
     "wall"     : ({ "wood", "wooden", "reinforced" }),
     	]) );
  SetAmbientLight(40);
  SetInventory( ([
     TAI_RI_NPC "shopkeep" : 1,
  ]) );
  SetSmell( ([
    "default" : "The smell of leather and steel fills the air.",
    ]) );
  SetListen( ([
    "default" : "The shop is quiet and peaceful.",
    ]) );
}
