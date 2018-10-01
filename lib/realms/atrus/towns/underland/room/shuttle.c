#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetShort("a shuttle loading bay");
  SetExits( ([
    "west" : UNDER_ROOM "level2hub",
    ]) );
  AddExit("north", UNDER_ROOM "track", (: PreExit :) );
  SetSmell("The bay smells of oils and moldy brass.");
  SetListen("Steam vents hiss and pneumatic pistons woosh.");
  SetLong(
    "This large room has a rectangular gap in the center which, " 
    "is the right size for the Trans-Continental shuttle. The walkway surrounding "
    "the bay is wide enough for almost any cargo to be loaded into the shuttle "
    "from either side. The tunnel entrance is perfectly round to the north "
    "where the shuttle track has been laid down after boring straight through "
    "the very crust of the planet. To the west is the great city of Underland. "
    "To the south is a customs station where you can purchase tickets for the "
    "shuttle."
    );
  SetItems( ([
    ({ "walkway", "ground", "cargo", "boxes" }) : 
                    "The walkway of pure basalt has been polished from years"
                    "of use. Crates and boxes line the outer walls. Clearly "
                    "marked aisles have been drawn into the floor for safe "
                    "areas of travel.",
    ({ "station", "building", "customs" }) : 
                    "The customs station sits to the south. The entrance "
                    "has been butressed and reinforced with iron bands "
                    "that seem to groan under the weight of the mountain "
                    "above.",
    ({ "bands", "reinforcement", "butresses", "mountain", "up", "supports", "support" }) :
                    "The walls of the cave have been reinforced with large iron "
                    "supports that hold the bulk of the mountain overhead. The "
                    "ceiling is cross thatched with iron bands.",
    ({ "bay", "opening", "tunnel", "tracks" }) :
                    "The opening in the center of the room has large pistons mounted "
                    "top stop the shuttle during docking. The track laid in the center "
                    "of the opening is brightly polished from use under extreme weight, "
                    "while the basalt floor under which has been scrupulously swept "
                    "clean of any debris. The tracks sink into the tunnel opening "
                    "and fade away distantly under faintly glowing orange lights far to the "
                    "north.",

    ]) );
  SetEnters( ([
    "station" : UNDER_ROOM "station",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 2,
    ]) );
}

int PreExit() {
  if (this_player()->id("wanderer")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
