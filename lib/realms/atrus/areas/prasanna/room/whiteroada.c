#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("the Path of the Pure");
   SetLong("The polished granite road continues, bringing the city ever "
           "closer to the east, and disappearing into the distance to the "
           "west. The landscape here begins to flatten, with only a few "
           "groves of trees scattered against the hillsides. There appears "
           "to be a small path leading into one such grove to the south.");
   SetItems( ([ 
      ({ "polished granite", "granite" }) : 
         "This is granite mined from a far away quarry.",
      ({ "road" }) : 
         "This is the road known as The Path of the Pure. It leads to "
         "the lost city of Prasanna. ",
      ({ "landscape" }) :
         "Only a small number of trees and other wild plants grow here.",
      ({ "hillsides", "hillside","hills","hill" }) :
         "These are small rises in the terrain, hardly worthly of being "
         "called hills. ",
      ({ "path" }) :
         "This path leads into a grove of trees to the south.", 
      ({ "trees","tree" }) :
         "The trees here are sparse and look sickly.",
      ({ "plants","plant" }) :
         "These are a few wild plants, tumbleweed, and desert flowers mostly.",      ({ "grove"}) :
         "A group of trees bunched tightly together, as if to conceal "
         "something." ,      
      ({ "city" }) : 
         "This sprawling city lies to the east, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/whiteroad2", 
      "west" : PR_ROOM "/whiteroad",
      "south" : PR_ROOM "/grove1"
   ]) );
}

