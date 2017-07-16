#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;
int Post(string dir);

static void create() {
  ::create();
  SetShort("a path deeper into the grove");
  SetExits( ([
    "south" : AREA_ROOM "entrance",
    ]) );
  AddExit("north", AREA_ROOM "path02", 0, (: Post :) );
  SetObviousExits("south");
  SetLong("The path continues to the south from here. Trees line the path as "
          "it continues south, but to the north the trees seem to form a "
          "nearly impassable wall of wood. The path is covered in road dust "
          "here, as if the way is rarely travelled.");
  SetListen( ([
    "default" : "The sounds of birds come from the south.",
    ]) );
  SetSmell( ([
    "default" : "A faint tinge is in the air, mixing with the scent of trees.",
    ]) );
  SetItems( ([
    "path" : "The path is covered with a thick layer of dust, as if even "
             "the air does not disturb this grove. Footprints can be seen "
             "in the dust, though likely ages old.",
    "dust" : "The dust is a thick covering over the path. Footprints in the "
             "dust seem to lead to the north, through the trees!",
    ({ "footprint", "footprints" }) : "The footprints lead to the north, "
             "through the trees!",
    ({ "tree", "trees" }) : "The trees seem to be all but impassable.  Oddly, "
            "the trees seem to beckon travellers to go north.",
    ]) );
}

int Post(string dir) {
  if (!(this_player()->GetQuestCompleted("Explored Grove"))) {
    this_player()->AddQuest("the Explorer", "Explored Grove");
    this_player()->eventPrint("%^BOLD%^GREEN%^You have discovered a hidden grove!%^RESET%^");
    this_player()->AddDevelopmentPoints(10);
    }
  return 0;
}
