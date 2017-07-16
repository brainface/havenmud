#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
  SetDomain("Valley");
   SetClimate("temperate");
   SetShort("the Path of the Pure");
   SetLong("This road was painstakingly well crafted from polished granite, "
           "and consists of ten foot wide, twenty foot long sections, "
           "each chiseled with extreme care to fit its neighbor perfectly.  "
           "There are holes cut in the center of some pieces of granite which "
           "allow a small amount of grass to grow, with a large topiary in "
           "the center of each. The grass on either side of the road has been "
           "recently manicured. There are trees set back from the sides of the "
           "road. The road continues downward towards the city which looms "
           "against the horizon.");
   SetItems( ([ 
      ({ "grass" }) :
         "There are small patches of grass in the center of the holes for the "
         "topiary plants. The grass on the side of the road has been trimmed "
         "short with no visible weeds of any kind.",
      ({ "hole","holes" }) : 
         "There are six foot round holes cut out of the center of each section "
         "of granite for the topiary plants to grow through.",
      ({ "tree","trees" }) :
         "There are well groomed trees set back from the sides of the road. Many "
         "species of tree grow here, amazing for such high altitude.",
      ({ "polished granite", "granite" }) : 
         "This is granite mined from a far away quarry.",
      ({ "sections","section" }) : 
         "These are sections of granite which make up the road. They are ten "
         "feet long, and twenty feet wide.",
      ({ "neighbor" }) : 
         "Each piece of the road sits next to another almost seemlessly. ",
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
   SetInventory( ([
      PR_OBJ + "/dragt" : 1,
      PR_OBJ + "/liont" : 1
   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/whiteroada", 
      "west" : PR_ROOM "/cliff",
   ]) );
   SetSmell( ([ 
      "default" : "The scent of jasmine lingers in the air here, like "
                  "perfume.",
   ]) );
}
