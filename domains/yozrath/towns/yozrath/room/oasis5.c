#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_ROOM;

/* Cemetery room for Yozrath. */

static void create() {
  ::create();
  SetShort("a quiet repose near the Oasis in Yozrath");
  SetClimate("arid");
  SetExits( ([
    "south" : YOZRATH_ROOM "oasis3",
    ]) );
  SetLong(
    "This quiet repose off the main path of the oasis is a peaceful "
    "center of prayer for those souls lost in the desert. "
    "There are several small woven mats lying in the shade of some "
    "palm trees here, obviously designed for prayer abulations."
    );
  SetSmell("The air is fresh and pleasant.");
  SetListen("The breeze blows quietly through the palm branches.");
  SetItems( ([
    ({ "mat", "mats" }) : "The small woven mats are designed for prayer.",
    ({ "tree", "trees" }) : "These palm trees are not nearly as fruitful "
                            "as those to the south.",
    ]) );
  SetItemAdjectives( ([
    "mat" : ({ "small", "woven", "prayer" }),
    "tree" : ({ "palm" }),
    ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
    YOZRATH_OBJ "plaque" : 1,
    YOZRATH_NPC "healer" : 1,
    ]) );
}
