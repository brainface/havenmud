#include <lib.h>
#include "../copse.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a thick concentration of cherry blossoms");
  SetLong("Here the cherry blossoms become very thick."
          " Unfortunately the path is all but indistinguishable"
          " underneath a blanket of fallen cherry blossom petals."
          " It appears that the density of the trees let up"
          " a little to the south, while to the east it"
          " almost looks impassable.");
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
  SetSmell( ([
      "default" :"The sweet aroma of cherry blossoms in bloom lingers here.",
    ]) );
  SetInventory( ([
    COPSE_NPC + "caterpillar" : 3,
    COPSE_NPC + "butterfly" : 1,
    ]) );
  SetExits( ([
      "south" : COPSE_ROOM "room2",
      "east" : COPSE_ROOM "room6",
    ]) );
}


