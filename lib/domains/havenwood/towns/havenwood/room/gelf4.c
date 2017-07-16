#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a central clearing in the Havenwood");
  SetExits( ([
    "west"  : HWD_ROOM "/gelf1",
    "east"  : HWD_ROOM "/gelf6",
    "south" : HWD_ROOM "/gelf2",
    "north" : HWD_ROOM "/gelf3",
    ]) );
  SetLong(
    "This clearing serves as the general meeting place for the wild-elves "
    "of the Havenwood. Near the center of the clearing sits a large fire-pit "
    "that has seen obvious use. Some of the ground near the pit has been churned "
    "by the movements of a large object of some type. Far to the outside of the "
    "clearing the towering trees of the Havenwood rise into the sky."
    );
  SetItems( ([
    "ground" : "Upon review, the ground appears to have been churned deeply, "
               "almost as if by the roots of a tree moving!",
    "pit"    : "The fire-pit has seen obvious use, and the grass near it has "
               "been trampled down repeatedly.",
    "grass"  : "The grass has been trampled by the footsteps of the wild-elves "
               "in their dance.",
    ]) );
  SetSmell("The lingering scent of the last dance fire still hangs in the air.");
  SetListen("Birds chirp in the distant branches of the Havenwood.");
  SetInventory( ([
    HWD_NPC "/equipper" : 1,
    HWD_NPC "/repair_trainer" : 1,
    HWD_NPC "/spirit"   : 1,
    ]) );
}
