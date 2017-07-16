#include <lib.h>
#include "../copse.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small copse of cherry blossoms");
  SetLong("Littered upon the ground are countless"
          " pink petals of the cherry blossom trees"
          " the reside here. By sheer numbers alone"
          " they have obscured the path leading into the copse."
          " What discernible patches of the path are"
          " seen lead one to assume it leads in all"
          " cardinal directions. To the south one can"
          " travel back towards the Tairi Path,"
          " while the north seems to lead further"
          " into the copse. To the east and west"
          " the path appears to lead to clearings.");
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
                COPSE_NPC "butterfly" : 2,
                COPSE_NPC "caterpillar" : 1,
    ]) );
  SetSmell( ([
      "default" : "The sweet aroma of cherry blossoms in bloom lingers here.",
    ]) );
  SetExits( ([
      "north" : COPSE_ROOM "room5",
      "south" : COPSE_ROOM "room1",
      "east" : COPSE_ROOM "room3",
      "west" : COPSE_ROOM "room4",
    ]) );
}
