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
  SetShort("a crossroads of a path");
  SetExits( ([
    "south"     : HWD_ROOM + "/gelf7",
    "west"      : HWD_ROOM + "/gelf4",
    "north"     : HWD_ROOM + "/gelf8",
    ]) );
  AddExit("east", HAVENWOOD_AREAS "wood/rooms/beach1", (: PreExit :) );
  SetLong(
    "The path ends here at the edge of the Havenwood. To the east the "
    "woods open as they reach the sandy shores of the Ruined Sea. The "
    "trees are less impressive to the east, being normal trees and "
    "not those specifically tended by the druids of the Havenwood. "
    "Paths through the wild-elf settlement continue in nearly all "
    "other directions. A hollowed out tree serves as the barracks of the "
    "warriors and defenders of the Havenwood."
  );
  SetItems( ([
    ({ "trunk", "tree", "barracks" }) : "This tree serves as the local barracks.",
    ]) );
  SetEnters( ([
    "trunk" : HWD_ROOM "/fighter",
    ]) );
  SetSmell( ([
    "default" : "The scent of the Ruined Sea drifts in the air.",
  ]) );
  SetListen( ([
    "default" : "The sounds of the sea come from the east.",
  ]) );
}
