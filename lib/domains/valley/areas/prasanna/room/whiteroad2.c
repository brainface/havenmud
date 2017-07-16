#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("The Path of the Pure");
   SetLong("The polished granite road continues on, slightly inclined as it "
           "heads east, drawing ever closer to the city. The landscape "
           "around the road grows bare, almost to the point of becoming a "
           "desert. Only a few wildflowers and tiny shrubs seem to be able "
           "to survive. To the east a city towers against the sky. ");
   SetItems( ([ 
      ({ "polished granite","granite" }) : 
         "This is granite mined from a far away quarry.",
      ({ "road" }) : 
         "This is the road known as The Path of the Pure. It leads to the "
         "lost city of Prasanna. ",
      ({ "landscape" }) : 
         "The landscape here is bare, and leaves much to be desired. ",
      ({ "desert" }) : 
         "The land is dry, but not a desert yet.",
      ({ "wildflowers","wildflower","flowers","flower" }) : 
         "Unremarkable flowers grow here, wild ones with varied colors. ",
      ({ "tiny shrubs","shrubs","tiny shrub","shrub"  }) : 
         "These small plants are able to thrive, despite the lack of "
         "moisture. ",
      ({ "sky" }) : 
         "The sky here seems more blue than anywhere else. ", 
      ({ "city" }) : 
         "This sprawling city lies to the east, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting." 
   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/gates", 
      "west" : PR_ROOM "/whiteroada" 
   ]) );
}

