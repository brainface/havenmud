#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the HavenWood");
  SetDomain("HavenWood");
  SetLong("This forest seems cool and unnerving. The main road "
    "lies to the southwest while there seems to be a small clearing to the "
    "east. The trees filter the light so that the area has a dim, "
    "unreal quality. Many different varieties of trees and bushes "
    "line this part of the HavenWood.");
  SetExits( ([
     "east"   : HWD_ROOM + "/wood1",
     "southwest" : HWD_ROOM + "/wood3",
    ]) );
  SetItems( ([
     ({ "tree", "trees" }) : "The trees have a certain personality "
                             "about them, as if each was a living "
                             "creature with thoughts and feelings.",
     ]) );
}
