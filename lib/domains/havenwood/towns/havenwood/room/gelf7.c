#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the Havenwood");
  SetExits( ([
    "north" : HWD_ROOM + "/gelf6",
    "west"  : HWD_ROOM + "/gelf2",
    "south" : HWD_ROOM + "/gelf9",
   ]) );
  SetLong(
    "The path along the outer edge of the Havenwood continues "
    "to the north and west from here. A somber, black-tinged "
    "path leads to the south. To the west, the path circles "
    "around and past the local tanner, while to the north the "
    "path opens into a crossroads leading in many directions. "
    "A hollowed-out old tree stump here serves as the settlement's "
    "shrine to the Lady of Mercy."
    );
  SetItems( ([
    "path" : "The path continues north and west from here, "
             "but a path lined with black soot and ash heads "
             "south from here.",
    ({ "trees", "tree" }) : "The trees here are large and "
             "imposing things, obviously tended through "
             "magical means.",
    ({ "stump", "tree", "shrine" }) :
      "Apparently an old stump remaining from a truly massive "
      "tree. Smoky twirls of incense float out from the entrance. " 
    ]) );
  SetItemAdjectives( ([
    "stump" : ({ "hollowed", "out", "tree", "old" }),
    "path" : ({ "black", "tinged", "ash", "soot", "somber" }),
    ]) );
  SetSmell("A faint hint of the tannery comes from the west.");
  SetListen("Birds chirp in the branches above.");
  SetEnters( ([
    "shrine" : HWD_ROOM "/shrine",
    ]) );
}

