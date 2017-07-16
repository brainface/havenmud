//Illura@haven
//ship2
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside the ship");
  SetLong(
    "This ship's cargo hold is dark and stinks of bilge and offal. "
    "Empty casks and crates litter the floor here. Their goods may "
    "have fetched a decent price at the port of call for this "
    "ship, but they never made it there. The floor is wet with "
    "sludge and unknown substances. The corridor ends just "
    "west of here in the captain's cabin, and a way out is east."
  );
  SetExits( ([
    "west" : OIL_ROOM "/ship3",
    "east" : OIL_ROOM "/ship1"
  ]) );
  SetItems( ([
    ({"hold"}) : "You are inside the cargo hold of a ship.",
    ({"casks", "cask", "crate", "crates"}) : 
      "The crates and casks are all empty, and the wood is half rotted away "
      "on some.",
    ({"sludge", "substances", "substance"}): 
      "After a second though, you decide not to see what it really is.",
    ({"corridor"}) : "The length of the ship extends westward and eastward."
  ]) );
  SetItemAdjectives( ([
    "hold" : ({"cargo"}),
    "casks" : ({"empty"}),
    "sludge" : ({"unknown"})
  ]) );
  SetInventory( ([
    OIL_NPC + "sailor" : 2,
  ]) );
  SetListen( ([
    "default" : "The ship creaks and groans.",
  ]) );
  SetSmell( ([
    "default" : "The stench is pretty powerful.",
  ]) );
}
