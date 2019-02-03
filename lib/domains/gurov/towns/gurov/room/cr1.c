#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetShort("the Center Road near the gate");
  SetExits( ([
    "north" : GUROV_ROOM "cr2",
    "east"  : GUROV_ROOM "or3",
    "south" : GUROV_ROOM "gate",
    ]) );
  SetLong(
    "The Center Road runs off to the north from here, while to the east lies "
    "the Outer Road, which follows the town wall around the city. Directly to "
    "the south is the city gate, which leads out into the lands of the Principality "
    "of Gurov. The city wall is a large stone wall which completely surrounds the "
    "city. From here, various buildings can be seen to both the north and east, "
    "but no buildings are built so close to the gate."
    );
  SetListen( ([
    "default" : "The sounds of city life are louder to the north.",
    ]) );
  SetItems( ([
    "wall" : "The town wall is approximately 20 feet tall and very thick.",
    ({ "building", "buildings" }) : "The buildings are off to the north and east.",
    "gate" : "The gate is a wooden and iron structure designed to keep out "
             "raiders from the Principality's neighbors.",
    ({ "pile", "piles" }) : "The piles of horse dung are thick and smelly.",
    ]) );
  SetSmell( ([
    "default" : "The smells of horse offal waft from piles near the gate.",
    "pile"    : "The piles smell of horse dung.",
    ]) );
  SetItemAdjectives( ([
    "wall" : ({ "stone", "large", "city", "town" }),
    "gate" : ({ "city", "town" }),
    ]) );
  SetInventory( ([
    ]) );
}
   
    
