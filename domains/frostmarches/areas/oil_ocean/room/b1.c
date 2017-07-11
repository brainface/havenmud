//Illura@haven
//b1
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the oil ocean");
  SetLong(
    "Here the oil ocean meets the true one, salty and thick with "
    "temperamental quicksand. The oil casts rings of rainbows "
    "over the ground in an almost metaphysical swirl. One must "
     "carefully pick one's way here so that one does not sink up "
    "to one's neck with a casual misstep."
  );
  SetExits( ([
    "south" : OIL_ROOM "/b2",
    "west" : OIL_ROOM "/a1",
    "east" : OIL_ROOM "/c1"
  ]) );
  SetItems( ([
    ({"oil", "ocean"}) : "Here the oil ocean laps up against the sea, but the black ooze under your feet is nearly indistinguishable from the other parts of this area.",
    ({"quicksand"}) : "One false move, and you could end up stuck, sinking down into unforgivable blackness.",
    ({"ring", "rings", "rainbow", "rainbows"}) : "The oil makes rainbows on the water, brightening up the scenery.",
  ]) );
  SetItemAdjectives( ([
    "quicksand" : ({"temperamental"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "creature" : 3,
  ]) );
  SetListen( ([
    "default" : "You can almost hear the crash of the surf from here.",
  ]) );
  SetSmell( ([
    "default" : "A light wind brings the ocean breeze to your nostrils.",
  ]) );
}
