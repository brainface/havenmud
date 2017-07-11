#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("deep in the forest");
   SetLong("The trees thicken quickly, darkening the area considerably. "
           "The path here looks much less travelled, and few plants "
           "continue to grow beneath the canopy of tree branches. "
           "A bit further to the south, there appears to be a small "
           "clearing in the forest.");
   SetItems( ([ 
      ({ "small path","path" }) :
         "This path is well worn and looks a bit grown over by weeds.", 
      ({ "weeds","weed" }) :
         "The weeds here seem to be some of the few plants that can "
          "flourish in this forest.",      ({ "forest" }) : 
         "The forest thickens here, and starts to get darker.",
      ({ "trees","tree" }) : 
         "Evergreen trees, they look nice, smell nice, and are very rustic. ",
      ({ "clearing","small clearing" }) : 
         "Further to the south, the trees thin out into a clearing.",
      ({ "canopy" }) :
         "The tree branches hang overhead so closely together, that they "
         "form a canopy that blocks out most light.",
      ({ "branches","tree branches" })  :         
         "These overhanging tree branches form a thick canopy above the "
         "forest.",
      ({ "plants","plant" }) :
         "A few plants litter the area, most of which can survive with little "
         "light.",
   ]) );
   SetExits( ([ 
      "north" : PR_ROOM "/grove1", 
      "south" : PR_ROOM "/clearing",
   ]) );
}

