/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("the mountain path");
    SetLong("This is path up the side of a mountain. Various stones "
      "can be seen scattered on the sides of the path. "
      "There appears to be a small structure a bit further up "
      "the path.");
    SetItems( ([
        ({ "path" }) : "A worn path on the edge of the mountain.",
        ({ "stone", "stones" }) : 
        "There are all sizes of stones scattered around the path. "
        "they appear to be of the same material as the mountain itself.",
        ({ "mountain" }) : "One of they mountains in the Crystal Reaches "
        "range. The snowcap is far above you.", 
        ({ "structure", "small structure" }) : 
        "There is a small, stone structure a bit further up the mountain.",
      ]) );
    SetClimate("arid");   
    SetExits( ([
        "up" : RMS+"watch",
        "southwest" : RMS+"mpath2",
      ]) );
    SetInventory( ([
        NPC+"mdwarf" : random(3)+2,
        NPC+"fdwarf" : random(3)+2,
      ]) );
  SetDomain("Valley");
}

