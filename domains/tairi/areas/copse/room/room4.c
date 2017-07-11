#include <lib.h>
#include "../copse.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
  SetLong("This part of the copse appears to have been"
          " cleared away to create a lovely little"
          " picnic area. A ring of cherry blossoms"
          " provide excellent shade and scenery for"
          " any and all who wish to take a moment to"
          " appreciate their beauty. There is a path"
          " leading eastward towards a concentrated"
          " number of cherry blossom trees.");
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
    COPSE_NPC + "caterpillar" : 2,
    COPSE_NPC + "butterfly" : 2,
    ]) );
  SetExits( ([
      "east" : COPSE_ROOM "room2",
    ]) );
}
