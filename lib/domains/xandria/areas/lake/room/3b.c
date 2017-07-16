//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("near a building");
  SetClimate("arid");
  SetLong(
    "This is a green clearing near what appears to be a workshop "
    "of some kind. It also appears to be where broken or misformed "
    "pots come to die, from the looks of a few small piles of "
    "crockery that stand here. Another building can be seen to "
    "the south, and a dock on the banks of Lake Rantera is east. "
  );
  SetItems( ([
    ({ "clearing" }) : (: GetLong :),
    ({ "pots", "pot", "pile", "piles", "crockery" }) :
    "It seems people throw their mistakes here to forget about them. ",
    ({ "building", "workshop" }) :
    "The ceramic workshop is here, although the entrance is to the "
    "north, and the papermaking workshop is in the south.",
    ({ "dock" }) :
    "The dock is east. ",
  ]) );
  SetItemAdjectives( ([
  "pots" : ({ "broken", "misformed" }),
  "piles" : ({ "small" }),
  ]) );
  SetListen("Occasionally, someone throws another pot onto the "
    "stack with a clatter.");
  SetSmell("The air smells fresh and slightly like the lake.");
  SetExits( ([
    "east" : LAKE_ROOM "/3c",
    "south" : LAKE_ROOM "/4b",
  ]) );
  SetInventory( ([
    LAKE_NPC "ibis" : 2,
  ]) );
}
