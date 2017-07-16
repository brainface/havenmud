//Illura@haven
//e2
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("a ramshackle factory");
  SetLong(
    "A large, yet poorly constructed factory stands here, "
    "slapped together from old planks and rocks and bent "
    "rusty nails. Parts of the building have sunk into the "
    "ooze and have since been abandoned, but the main "
    "structure, although spackled with murk, has weathered "
    "its time in the oil ocean well so far. Great smokestacks "
    "rise high above the factory, pumping out black fumes."
  );
  SetExits( ([
    "north" : OIL_ROOM "/e1",
    "south" : OIL_ROOM "/e3",
    "west" : OIL_ROOM "/d2",
    "east" : OIL_ROOM "/f2"
  ]) );
  SetItems( ([
    ({"factory", "building"}) : "The factory appears to be running, although certainly not smoothly.",
    ({"plank", "planks", "nails", "nail", "rocks", "rock"}) : "The factory is made of slipshod materials put together with a sense of carelessness.",
    ({"ooze", "oil", "murk"}) : "The ever present oil ocean doesn't improve the scenery for the workers of this factory.",
    ({"smokestack", "smokestacks", "fumes", "smoke"}) : "A steady stream of black smoke comes out of the stacks. It smells of burnt tar and noxious fumes."
  ]) );
  SetEnters( ([
    "factory" : OIL_ROOM "/factory1"
  ]) );
  SetItemAdjectives( ([
    "factory" : ({"large"}),
    "plank" : ({"old"}),
    "smokestack" : ({"great", "black"})
  ]) );
  SetInventory( ([
    OIL_NPC + "lizard" : 3,
  ]) );
  SetListen( ([
    "default" : "A constant thrum of banging and activity comes from the factory, punctuated by occasional shouts and crashes.",
  ]) );
  SetSmell( ([
    "default" : "The air hangs thickly with smoke and tar.",
  ]) );
}
