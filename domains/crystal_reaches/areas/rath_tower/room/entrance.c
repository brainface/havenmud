#include <lib.h>
#include "../rath.h"
#define EXIT "/domains/crystal_reaches/areas/gwonish/room/path10"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetShort("a vaulted entryway");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetInventory( ([
     TOWER_N + "/guard" : 2,
     ]) );
  SetLong("The entrance room to the tower is a large spacious room "
         "that could almost be called cozy if not for the chill that "
         "hangs in the air like a midwinter morning without remorse. "
         "The tapestries that line the walls seem dull and faded, yet "
         "do not stand out of place in a hall wherein all the furnishings "
         "are easily hundreds of years old.  There is a set of stairs "
         "at the southern end of the hall which leads both up and down, "
         "and passages leading east, south, and west.");
  SetSmell( ([
    "default" : "There is an odor of dust and decay in the air.",
    ]) );
  SetItems( ([
    ({ "tapestry", "tapestries" }) : "These old and forlorn battle "
                                     "trophies hang on the walls like "
                                     "monuments to a forgotten king.",
    ({ "stairs", "set of stairs" }) : "The stairs seem older, but could "
                                      "still hold the weight of many "
                                      "creatures.",
    ({ "furniture", "furishings" }) : "The furniture is old and scattered "
                                      "about, its worm-eaten covering "
                                      "nearly gone with the ages.",
     ({ "walls", "wall" }) : "The walls are dusty and old, with moldering "
                             "tapestries hanging about like old refuse.",
  ]) );
  SetExits( ([
    "south" : TOWER_R + "/l1s1",
    "east"  : TOWER_R + "/l1e1",
    "west"  : TOWER_R + "/l1w1",
    "up"    : TOWER_R + "/l2r1",
    "down"  : TOWER_R + "/l0r1",
  ]) );
  AddExit("out", EXIT, (: PreExit :) );
}

int PreExit(string dir) {
  if (member_array("tower_guard", this_player()->GetId()) != -1) {
    message("system", 
      capitalize(this_player()->GetShort()) + " peers out, "
      "but decides not to go that way.", this_object() );
    return 0;
    }
  return 1;
}
