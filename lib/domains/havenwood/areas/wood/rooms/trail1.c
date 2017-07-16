//coded by Syra 8/97
#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pathway");
  SetDomain("Havenwood");
  SetLong("A small animal trail seems to have been made to cut "
    "through the dense trees that abound in this part of "
    "HavenWood. The trail continues to the northwest while to "
    "the south lies the main road. The dense foliage makes it "
    "hard to see very far into the wood. Small animal tracks can "
    "be seen leading in all directions.");
  SetItems( ([
    ({"tracks", "track"}) : "The tracks lead in all directions.",
    "foliage" : "The foliage is quite thick here.",
             ({"main road","road"}): "To the south is the main road "
               "in Havenwood.",
             ({"havenwood","woods","wood"}): (:GetLong:),
             ({"small animal trail","animal trail","small trail","trail"}):
               "Judging from its usage, there are probably many animals "
               "that come by here daily.",
             ({"tall trees","dense trees","trees","tree","tall tree",
               "dense tree"}):
               "The trees are very tall and are abundant here.", 
     ]) );
  SetItemAdjectives( ([
    "foliage" : ({"dense", "thick"}),
    "tracks" : "animal",
    ]) );
  SetExits( ([
            "south" : "wood1",
            "northwest" : HWD_ROOM + "/trail2"
     ]) );
  SetInventory( ([
            HWD_NPC + "/squirrel" : 2,
            HWD_NPC + "/dunerabbit" : 1,
     ]) );
 }


/* Approved by Amelia on Thu Sep 11 23:24:31 1997. */
