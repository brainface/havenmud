#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(3);
    SetClimate("underground");
    SetShort("a T intersection");
    SetLong("This is a T intersection in a roughly hewn corridor.  It "
            "branches off to the east, west and north.  The corridor "
            "is approximatly ten feet in each dimension.  Off to the west "
            "a small chamber can be seen. The eastern route heads off to "
            "a long stretch of corridor and the north leads to the cave "
            "entrance.  The corridor is of soft grey stone.  There is "
            "a crudely made sconce in the wall.");
    SetItems( ([
      ({"sconce", "crudely made sconce", "empty sconce"}) :
        "This is a poorly made and empty sconce.",
      ({"T", "T intersection", "corridor", "branch", "branches",
        "intersection"}) :
        "This is a T intersection heading to the north, east, and west.",
     ({"west", "chamber"}) :
        "This heads off to a small chamber.",
     "entrance" :
        "This heads to the entrance.",
     ({"route", "easten route"}) :
        "This heads to a large stretch of corridor.",
     ({"stone", "grey stone", "rock", "sedimentary rock"}) :
       "This is a soft sedimentary rock, easily worn by chisel or water.",
            ]) );
    SetListen( ([
      "default" :
        "An occasional voice can be heard in all directions, the one "
        "from the west being much lower.  The frequent drip of water "
        "can be heard.",
             ]) );
    SetSmell( ([
      "default" :
        "A foul stench comes from the north, while the smell of burnt "
        "wood is very faint.",
            ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "caves",
      "east"  : CAVES_ROOM + "cavet1",
      "west"  : CAVES_ROOM + "caveogre",
            ]) );
}
