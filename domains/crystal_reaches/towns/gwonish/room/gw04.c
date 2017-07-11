#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
  ::create(); SetClimate("sub-tropical");
  SetShort("a path through the Gwonish Swamp");
  SetDayLight(-10);
  SetNightLight(-10);
  SetExits( ([
    "southwest" : GWONISH_ROOM "gw01",
    "west"      : GWONISH_ROOM "gw02",
    "north"     : GWONISH_ROOM "gw08",
    ]) );
  SetLong("The path through the swamp leads off southwest, west, and north "
          "from here. The murky swampland has trees which overshadow the "
          "path and prevent too much light from getting in.  Lying on the "
          "path is a flimsy wooden shack.  Muck from the ground oozes along "
          "the path in a way that makes moving around a severe chore.");
  SetItems( ([
    "muck"   : "The muck is thick and hard to move through.",
    "ground" : "The ground is nothing more than thick muck.",
    "shack"  : "This flimsy wooden shack appears to serve as "
              "a central mail and news center for the citizens.",
    ({ "tree", "trees" }) : "The trees overhead keep the stars and light "
              "out of the swamp.",
    ]) );
  SetItemAdjectives( ([
    "shack" : ({ "flimsy", "wooden" }),
    ]) );
  SetEnters( ([
    "shack" : GWONISH_ROOM "post",
    ]) );
  SetSmell( ([
    "default" : "The smell of rotting vegetation is horrid and acidic.",
    ]) );
  SetListen( ([
    "default" : "Oozing muck and birdcalls can be heard.",
    ]) );
  SetInventory( ([
    GWONISH_NPC "mayor"    : 1,
    GWONISH_NPC "equipper" : 1,
    ]) );
}