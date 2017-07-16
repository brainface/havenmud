#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
  room::create();
SetClimate("indoors");
  SetShort("a cave within the mountains");
  SetLong("This cave is surprisingly neat.  The floor has been cleaned of the "
          "rocks and pebbles one would normally expect in a cave.  To the "
          "side of the cave, books have been nicely stacked.  Some papers lay "
          "haphazardly in the corner.  A path leads out from the cave towards "
          "a forest of some sort to the east.");
  SetListen( ([ "default" : "The whisling of the wind can be heard as it "
                            "passes outside the cave."]) );
  SetSmell( ([ "default" : "An awful stench assaults your nostrils."]) );
  SetItems( ([
    ({ "neat cave","cave" }) :
       (: GetLong() :),
    ({ "small path","path","forest to the east","forest" }) :
       "A small path leads out of the cave towards a forest to the east.",
    ({ "few large boulders","few boulders","large boulders","boulders",
       "large boulder","boulder","back of cave","back"}) :
       "The boulders piled up at the back of the cave seem to be blocking "
       "something.",
     ({ "side of cave","side","haphazardly stacked books","stacked books",
        "stacked book","books","book" }) :
        "The books stacked to the side of the cave are written in an "
        "unfamiliar language.",
     ({ "corner of cave","corner","haphazardly lying papers","lying papers",
        "lying paper","paper","strange drawings","strange inscriptions",
        "drawings","inscriptions","strange drawing","drawing",
        "strange inscription","inscription" }) :
        "The papers the lie haphazardly in the corner have strange drawings "
        "and inscriptions on them."
  ]) );
  SetObviousExits("out");
  SetExits( ([
    "out" : F_ROOM "forest8"
  ]) );
  SetInventory( ([
    F_NPC "mage" : 1
  ]) );
}