#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
  SetDomain("Valley");
   SetClimate("temperate");
   SetShort("the Path of the Pure");
   SetLong("This road look painstakingly well crafted from polished granite, "
           "and consists of ten foot wide, twenty foot long sections, "
           "each chiseled with extreme care to fit its neighbor perfectly.  "
           "The road continues downward towards the city which looms against "
           "the horizon.");
   SetItems( ([ 
      ({ "polished granite", "granite" }) : 
         "This is granite mined from a far away quarry.",
      ({ "sections","section" }) : 
         "These are seconds of granite which make up the road. They are ten "
         "feet long, and twenty feet wide.",
      ({ "neighbor" }) : 
         "Each piece of the road sits next to another. ",
      ({ "road" }) : 
         "This is the road known as The Path of the Pure. It leads to "
         "the lost city of Prasanna. ",
      ({ "horizon" }) : 
         "The sky meets the ground far off in the distance but the city "
         "Prasanna takes up almost the entire skyline. ",
      ({ "city" }) : 
         "This sprawling city lies to the east, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.", 
      ({ "buildings" }) :
         "The buildings of the city to the east seem to give off an eerie, "
         "inviting glow. "   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/whiteroada", 
      "west" : PR_ROOM "/cliff",
   ]) );
   SetSmell( ([ 
      "default" : "The scent of jasmine lingers in the air here, like "
                  "perfume.",
   ]) );
}


