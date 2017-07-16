#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the HavenWood");
  SetDomain("HavenWood");
  SetLong("The HavenWood looks much like any other "
    "forest that one could find on Kailie. During the day, the sky "
    "shines brightly down onto the ground, where patches of leaves "
    "cover the forest floor like a blanket of protection. To "
    "the northeast is the path theat continues to trudge through the "
    "wood. Off to the southwest, a road can be seen.");
  SetItems( ([
     ({ "leaf", "leaves" }) : "The leaves cover the ground fully.",
     ({ "sound", "sounds", "odd sounds", "odd sound" }) :
          "You cannot look at a sound!",
      ]) );
  SetListen( ([
     "default" : "The sounds of the forest give a backdrop to the wood.",
     "sound" : "The sounds are truly horrible whispers of voice.",
      ]) );
  SetExits( ([
     "northeast" : HWD_ROOM + "/wood2",
     "southwest" : HWD_ROOM + "/wood4",
      ]) );
  }
