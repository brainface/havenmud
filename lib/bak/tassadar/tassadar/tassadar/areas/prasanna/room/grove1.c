#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
  SetDomain("Valley");
   SetClimate("temperate");
   SetShort("a small forest");
   SetLong("The small path advances into a lush forest, oddly out of place "
           "on the barren mountain. The path continues to the south, and the "
           "trees begin to thicken, growing into almost a solid wall around "
           "the path.");
   SetItems( ([ 
      ({ "small path","path" }) :
         "This path is well worn and looks to be travelled often.",
      ({ "lush forest", "forest" }) : 
         "This forest looks out of place on such a barren mountain, yet "
         "life seems to be flourishing.",
      ({ "barren mountain","mountainside","mountain" }) : 
         "This mountain is both mysterious and beautiful, its past remains "
         "a puzzle.",
      ({ "trees","tree" }) : 
         "These are mostly pine trees, the sort that grow on mountainsides. ",
      ({ "solid wall","wall" }) :  
         "The trees here are so close together, it's almost a wall.",   ]) );
   SetExits( ([ 
      "north" : PR_ROOM "/whiteroada", 
      "south" : PR_ROOM "/grove2",
   ]) );
   SetSmell( ([ 
      "default" : "A woodsy scent of pine and damp foliage fills the air. ",
   ]) );
}

