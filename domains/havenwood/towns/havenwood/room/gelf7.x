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
    "A hollowed-out tree trunk here serves as the settlement's "
    "shrine to Harmony."
    );
  SetItems( ([
    "path" : "The path continues north and west from here, "
             "but a path lined with black soot and ash heads "
             "south from here.",
    ({ "trees", "tree" }) : "The trees here are large and "
             "imposing things, obviously tended through "
             "magical means.",
    ({ "hollowed-out tree trunk", "tree", "trunk", "shrine" }) :
             "This hollowed-out tree trunk serves as the "
             "shrine to Harmony.",
    ]) );
  SetItemAdjectives( ([
    "hollowed-out tree trunk" : ({ "hollowed", "out", "tree" }),
    "path" : ({ "black", "tinged", "ash", "soot", "somber" }),
    ]) );
  SetSmell("A faint hint of the tannery comes from the west.");
  SetListen("Birds chirp in the branches above.");
  SetEnters( ([
    "shrine" : HWD_ROOM "/shrine",
    ]) );
}


