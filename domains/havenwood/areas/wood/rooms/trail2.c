//coded by Syra 8/97
#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pathway");
  SetDomain("Havenwood");
  SetLong("The woods open up to form a clearing carpeted with "
         "short shrubs. The animal trail meanders through the "
         "clearing and branches off to the southeast, east and west. "
         "To the north, northwest, and northeast there is a wall of trees "
         "that makes it impossible to go in that direction. There "
          "appears to be some movement to the southwest.");
  SetItems( ([
             ({"havenwood","woods","clearing","wood"}): (:GetLong:),
             ({"thick layer of shrubs","thick layer","layer",
               "short shrubs","shrubs","shrub","blanket","carpet"
               "low shrubs","short shrub","low shrub",}) :  
               "A thick layer of low shrubs blanket the clearing. ", 
             ({"wall of trees","trees","tree"}) : "The trees become "
               "very thick around the clearing. It opens up to the east, "
               "west, southeast, and southwest.",
             ({"animal trail","trail"}) : "The animal trail wanders "
               "through the clearing and heads in several directions: "
               "west, east, and southeast.",
     ]) );
  SetObviousExits("southeast, east, west");
  SetListen( ([
    "default" : "The chittering of squirrels can be heard in the distance.",
    ]) );
  SetSmell( ([
    "default" : "The area smells rather mossy.",
    ]) );
  SetExits( ([
            "southeast" : HWD_ROOM + "/trail1",
            "east"      : HWD_ROOM + "/trail6",
            "west"      : HWD_ROOM + "/trail4",
            "southwest" : HWD_ROOM + "/trail3",
     ]) );
  SetInventory( ([
            HWD_NPC + "/robin" : 1,       
     ]) );
  SetListen( ([
            ({"default","wind"}) : "The wind whistles through here. ",
     ]) );

 }
