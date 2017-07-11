#include <lib.h>
#include <domains.h>
#include "../wood.h"
inherit LIB_ROOM;

int PreExit() {
  if (this_player()->id("havenwood_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

static void create() {
  room::create();
  SetShort("in the Havenwood");
  SetExits( ([
    "southwest" : HWD_ROOM + "/gelf1",
    "south"     : HWD_ROOM + "/gelf4",
    "east"      : HWD_ROOM + "/gelf8",
    ]) );
  AddExit("west", HAVENWOOD_AREAS "gnome_lab/room/clearing", (: PreExit :) );
  SetLong(
    "The path around the Havenwood clearing continues to the southwest "
    "and east from here. Directly to the south is a large clearing set "
    "within the Wood. A small path to the west leads to a treehouse that "
    "can be seen from here. One of the trees here seems to have had its "
    "trunk hollowed out to serve as a general store for the Havenwood."
    );
  SetItems( ([
    "path" : "Paths leads southwest and east from here, and a small path "
             "leads west to the home of the gnomish mage.",
    ({ "trunk", "store" }) :
             "The hollowed out tree trunk serves as a general store.",
    ]) );
  SetItemAdjectives( ([
    "trunk" : ({ "general", "hollowed", "out" }),
    ]) );
  SetEnters( ([
    "trunk" : HWD_ROOM "/store"
    ]) );
  SetSmell("An odd scent wafts from the west.");
  SetListen("Birds chirp in the branches high above.");
}
