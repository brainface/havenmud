#include <lib.h>
#include "path.h"
inherit LIB_FISHING;
static void create() {
  fishing::create();
  SetShort("a rocky outcropping");
  SetObviousExits("south");
  SetExits( (["south" : GLEN + "/rooms/path3"]));
  SetLong("The grass suddenly fades away to sheer rock here.  "
             "There is a large, rocky outcropping that seems to "
             "grow directly from the earth.   It extends several "
             "feet out into the stream.  The stream runs slowly by "
             "as it flows on to it's unseen destination. ");
  SetInventory(([GLEN + "/npc/fisherman.c" : 1]));
  SetItems( ([
        "grass" : "The grass is green.",
       ({ "large rocky outcropping","rocky outcropping","outcropping",
          "rock"}) : 
                     "The rock is greyish in color and very smooth.  It "
                     "would probably make for a good place to fish.",
       ({"earth","dirt"}) : 
                     "It's ONLY dirt!",
       ({"stream"}) :
                     "The stream looks like it might contain some fish.",
       ({"fish"}) :
                     "Do you expect them to just swim up to you and "
                     "say hello?",
       ({"unseen destination","destination"}) :
                     "You look silly trying to find an UNSEEN destination!"
          ]) );
  SetListen( (["default" : "The stream murmurs as it flows by."]) );
  SetSmell( (["default" : "The area smells rather fishy."]) );
  SetSpeed(5);
  SetFish( ([
     "/std/fish/guppy" : 300,
     ]) );
  SetChance(30);
  SetMaxFishing(14);
  }
