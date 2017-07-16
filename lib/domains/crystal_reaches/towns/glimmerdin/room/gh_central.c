#include <lib.h>
#include "../path.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(25);
  SetShort("the Center of Glimmerdin");
  SetLong(
    "The Center of Glimmerdin is a massive town square frequented by "
    "all the denizens of the city. The stone paving surrounds a large "
    "pool here which provides water (and food!) for the town. Off to "
    "the south, the Great Hall seems to lead to the tunnel exiting "
    "the town, while to the north the Great Hall seems to lead deeper "
    "into the city. Carved into the western wall of the hall is a "
    "fortified keep that serves as the center of government in Glimmerdin. "
    "Built into the east is the home of the Glimmerdin Militia and the "
    "fighter training hall. Tucked into the southwest corner of the "
    "hall is a small shop."
    );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "keep", }) :
      "The Keep seems to be built into the western side of the hall, "
      "and houses the government of Glimmerdin.",
    ({ "hall", }) :
      "The fighter training hall is home to the Glimmerdin Militia.",
    ({ "paving", "square" }) : 
      "The stone paving is neat and very well organized with no gaps "
      "or missing stones.",
    ({ "shop" }) :
      "The small shop is tucked into the southwest corner of the hall.",
    ]) );
  SetItemAdjectives( ([
    "keep" : ({ "fortified", }),
    "hall" : ({ "fighter", "training", "militia", }),
    "paving" : ({ "stone", }),
    "shop" : ({ "small", }),
    ]) );
  SetExits( ([
    "south" : G_ROOM "gh_south",
    "north" : G_ROOM "gh_north",
    ]) );
  SetEnters( ([
    "shop" : G_ROOM "shop",
    "keep" : G_ROOM "keep",
    "hall" : G_ROOM "fighters",
    ]) );
  SetSmell( ([ 
    "default" : "The odors here are too numerous to catalog.",
    ]) );
  SetListen( ([
    "default" : "Trying to concentrate on listening to any one "
                "thing is much too difficult.",
    ]) );
  SetInventory( ([ 
    G_NPC "basic_guard" : 1,
    G_NPC "rat_vendor"  : 1,
    G_OBJ "pool"        : 1,
    ]) );
  SetSpeed(5);
  SetChance(10);
  SetMaxFishing(4);
  SetFish( ([
    DIR_STD "fish/trout" : 20,
    ]) );
}
