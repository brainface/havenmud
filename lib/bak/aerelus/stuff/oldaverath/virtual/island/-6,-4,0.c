/*  the great gate */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("the gates of Glistendin");
  SetLong("As the path curves around a large stone uprising, "
    "it encounters the great mithril gates of Glistendin. Long "
    "hidden from the view of the outside world, the gates are rarely "
    "seen or entered by any other races save the dwarves who "
    "inhabit Glistendin's depths. The area around the gates seems "
    "to have been subjected to same sort of barrage of stones as "
    "the rest of the path; however, the stones that once obstructed "
    "access to the gates were easily moved aside and actually stacked "
    "even though many of them are large beyond comprehension. "
    "The great mithril gates stand open here despite the solitary "
    "nature of the dwarven folk.");
  SetItems( ([
    ({"path", "trail", "uprising"}) :
      "The path curves around a rocky uprising then encounters "
      "the gates of Glistendin.",
    ({"gates", "gate"}) :
      "The great mithril gates stand open, awaiting entry.",
    ({"area", "stone", "stone"}) :
      "The area around the gate seems to have been cleared of "
      "stones.",
    ({"stacks", "stack"}) :
      "The stones are stacked up away from the gate.",
    ({"peak", "peaks", "mountain", "mountainside"}) :
      "The two towering stone peaks are part of a greater mountain.",
  ]) );
  SetItemAdjectives( ([
    "path" : ({"chaotic", "rocky", "curving", "winding", "rugged",
       "mountain"}),
    "gates" : ({"great", "mithril", "open"}),
    "area" : ({"cleared"}),
    "peak" : ({"two", "towering", "stone", "jagged"})
  ]) );
  SetExits( ([
    "north" : AVERATH_ISLAND + "-6,-3,0",
        ]) );
  AddExit("east", AVERATH_ISLAND + "-5,-4,0", (: PreExit :) );
  SetSmell( ([
    "default" : "The air is dusty but fresh.",
  ]) );
  SetListen( ([
    "default" : "Stones are clattering down nearby mountainsides.",
  ]) );
  SetInventory( ([
    G_NPC "guard1_wander" : 2,
  ]) );
}

int PreExit(string dir) {
  if (this_player()->id("town_wander")) return 0;
  return 1;
}
