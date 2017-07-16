#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../gwonish.h"

inherit LIB_FISHING;

static void create() {
  ::create(); SetClimate("sub-tropical");
  SetShort("a small landing");
  SetLong("The swamp opens here to a small landing on the shores of the "
          "sea. Far off to the south, the blue waves spread out endlessly "
          "into the horizon. To the north, the thick vegetation of the "
          "Gwonish Swamp stands as a mute testiment to the evil side of "
          "nature. Thin trails lead off into the swamp.");
  SetItems( ([ 
    ({ "trail", "trails"}) :
       "The trail is a barely-passable maze through the swamp.",
    "vegetation" : "Willow trees and vines grow from the "
                   "muck that passes as ground here.",
    ({ "muck", "ground" }) : "The ground is a thick, viscous solution "
                   "that vaguely resembles mud.",
    ({ "tree", "trees" }) : "Willow trees and other drooping plants "
                   "seem to hang in sorrow over the swamp.",
    ({ "vine", "vines" }) : "The vines droop low from the trees.",
     ]) );
  SetExits( ([ "north"     : GWONISH_ROOM "gw02",
               "northwest" : GWONISH_ROOM "gw03",
               "northeast" : GWONISH_ROOM "gw04",
               "south"     : INNERSEA_VIRTUAL "ocean/-93,-2",
               ]) );
  SetInventory( ([ 
    ]) ); 
  SetSmell( ([ 
    "default" : "Wet rotting vegetation nearly overpowers your "
                "olfactory system.",
    ]) );
  SetListen( ([ 
    "default" : "The groan and croak of frogs fills the air.",
     ]) );
  SetSpeed(5);
  SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
    ]) );
  SetChance(25);
  SetMaxFishing(12);
}
