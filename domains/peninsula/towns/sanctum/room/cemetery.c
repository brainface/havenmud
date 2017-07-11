#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a quiet contemplation glade");
  SetExits( ([
//    "south" : ROME_ROOM "kylin_temple",//does not map kylin temple is several rooms away
    "out" : ROME_ROOM "rd02",
    ]) );
  AddWarmth(-10);
  SetLong("This quiet glade serves as the beacon to which the souls "
          "of Sanctum's citizens return if they are killed. Arranged "
          "around the glade are several large oak trees.  Their branches "
          "stretch to the sky as if to defy the escape for anyone unlucky "
          "enough to find their soul kept here. Marble benches are "
          "spaced around the central glade area, in the shade of several "
          "of the oak trees.");
  SetItems( ([
    ({ "tree", "trees", "oak", "oaks" }) : "The oak trees serve to "
       "shield this grove from the less pious of Sanctum's citizens.",
    ({ "bench", "benches" }) : "The marble benches are delicately "
       "arranged, but appear to weigh several thousand pounds each.",
    ]) );
  SetItemAdjectives( ([
    "bench" : ({ "marble" }),
    "tree" :  ({ "oak", "large" }),
   ]) );
  SetInventory( ([
     STD_OBJ "reztotem" : 1,
     ROME_NPC "healer" : 1,
    ]) );
  SetSmell( ([
    "default" : "The glade has a refreshing woodsy smell.",
    ]) );
  SetListen( ([
    "default" : "The glade sits in silence.  Not even birds dare disturb it.",
    ]) );
}
