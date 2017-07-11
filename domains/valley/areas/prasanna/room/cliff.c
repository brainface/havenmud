#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("a cliff overlooking the Crystal Reaches");
   SetLong("A small path emerges from the cave, and nearly walks straight off "
           "the edge of a cliff. The rock face continues downward as far as "
           "the eye can see, and clouds blanket the area. Mountaintops "
           "pierce the clouds and surround the giant formation. A strange "
           "sort of energy hangs in the air, as it would seem that this once "
           "mighty mountain, had it's peak torn off to accomodate the city "
           "now nestled upon it. To the north, a wide road of white stone "
           "begins it's trek towards the city. ");
   SetItems( ([ 
      ({ "path" }) :
          "This path emerges from a nearby cave.",
      ({ "edge" }) :
          "The edge of the cliff looks precarious, getting too close may be "
          "quite hazardous.",
      ({ "face" }) :
          "The cliff face continues downward for a long long way.",
      ({ "buildings" }) :
          "Off in the distance, the buildings of the city rise up and seem "
          "to give off an eerie glow.",
      ({ "clouds","cloud" }) :   
         "These clouds look puffy and soft and surround the mountain peaks "
         "below as far as the eye can see. ",
      ({ "cave" }) : 
         "This cave looks dark, cold, and uninviting.",
      ({ "mountaintops","mountaintop" }) : 
         "The majestic mountaintops are snow covered and breathtaking. ",
      ({ "formation", "mountain" }) : 
         "This giant mountain is missing it's top, yet somehow manages to "
         "still look quite beautiful. ",
      ({ "city" }) : 
         "This sprawling city lies to the east, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
      ({ "road" }) : 
         "The road is made of beautiful polished granite and leads off to "
         "the east. It looks very well maintained. ", 
      ({ "white stone","polished granite","stone","granite" }) :
         "The road heading east is made of polished granite, it looks "
         "quite beautiful.",
   ]) );
   SetInventory( ([ 
       PR_NPC + "/eagle" : 1 
   ]) );
   SetExits( ([ 
       "east" : PR_ROOM "/whiteroad" 
   ]) );
   SetEnters( ([ 
       "cave" : PR_ROOM "/stairtop" 
   ]) );
   SetSmell( ([ 
       "default" : "The air is crisp and refreshing." 
   ]) );
}

