#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a cramped general shop");
  SetClimate("indoors");
  SetTown("Glimmerdin");
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetAmbientLight(30);
  SetLong(
    "This small cave is stocked to the rafters with merchandise "
    "of all varieties. Shelves are built into the sides of the "
    "cave and little has been done in the way of decoration. "
    "This shop seems to be the least pretentious building in "
    "all of Glimmerdin."
    );
  SetItems( ([
    ({ "shelf", "shelves" }) :
        "The shelves are simple rock outcroppings sticking out "
        "from the wall.",
    ({ "wall", "walls" }) : 
        "The walls are unfinished rock.",
    ({ "merchandise" }) :
        "The merchandise seems to be of the normal, mundane sort.",
    ]) );
  SetInventory( ([
    G_NPC "bruce" : 1,
    G_NPC "merchant_prince" : 1,
    ]) );
  SetSmell( ([
    "default" : "The room has a dusty, musty odor.",
    ]) );
  SetListen( ([
    "default" : "Sounds of vibrant life come in from the Great Hall.",
    ]) );
  SetExits( ([
    "out" : G_ROOM "gh_central",
    ]) );
}