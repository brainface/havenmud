#include <lib.h>
#include "../copse.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small path");
  SetLong("Littered upon the ground are countless"
          " pink petals of the cherry blossom trees"
          " the reside here. By sheer numbers alone"
          " they have obscured the path leading into the copse."
          " What discernible patches of the path are"
          " seen lead one to assume it leads both"
          " north and south. To the south the Tairi"
          " Path is visible, while the north seems"
          " to lead further into the copse.");
  SetItems( ([
      ({ "blossom", "cherry blossom", "tree", "trees" }) :
      "These trees are responsible for the myriad of flower"
      " petals found upon the path and surrounding area.",
      ({ "petal", "petals" }) :
      "These petals are of a light pink hue. Because there"
      " are so many petals, it is hard to see the ground"
      " beneath them.",
      ({ "path" }) :
      "The path seemingly winds between the cherry blossoms"
      " but it is hard to tell because of the large number"
      " of petals on the ground.",
    ]) );
  SetItemAdjectives( ([
      "petals" : ({ "pink", "blossom", "cherry blossom" }),
      "tree" : ({ "blossom", "cherry blossom" }),
    ]) );
  SetListen( ([
      "default" : "Light rustling noises sooth the copse.",
    ]) );
  SetInventory( ([
                COPSE_NPC "butterfly" : 1,
                COPSE_NPC "caterpillar" : 2,
    ]) );
  SetSmell( ([
      "default" : "The sweet aroma of cherry blossoms in bloom lingers here.",
    ]) );
  SetExits( ([
      "north" : COPSE_ROOM "room2",
      "south" : "/domains/tairi/virtual/tairi_path/-8,0",
    ]) );
}
