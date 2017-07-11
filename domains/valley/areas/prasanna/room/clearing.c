#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("a clearing deep in the forest");
   SetLong("The path comes to a clearing rather abruptly, as do the trees. "
           "A small log cabin sits cozily at the far side of the clearing. "
           "The cabin looks quite rustic and well constructed, and just big "
           "enough to house small family. A small trail of smoke rises from "
           "chimney.");
   SetItems( ([ 
      ({ "path" }) :
         "This path is well worn and looks a bit grown over by weeds.",
      ({ "weeds","weed" }) :
         "These are average weeds, not pretty, not ugly.",
      ({ "small forest","forest" }) : 
         "This forest looks out of place on such a barren mountain, yet "
         "life seems to be flourishing.",
      ({ "barren mountain","mountain" }) :
         "The mountain is mostly barren except for the small forest.",
      ({ "trees","tree" }) : 
         "These are mostly pine trees, the sort that grow on mountainsides. ",
      ({ "clearing","small clearing" }) : 
         "This clearing houses a small cabin, and not much else.",
      ({ "cabin" }) :
         "The cabin is built from many large logs, and looks quite sturdy.",
      ({ "family" }) :
         "There's no family here, get with it.",
      ({ "young children","children" }) :
         "Young children, infants, babies. None of which are present. ",
      ({ "chimney" }) :
         "Smoke drifts lazily from this chimney atop the house.",
      ({ "smoke" }) :
         "This is smoke rising from the chimney, someone must be home.", 
      ({ "logs","log" }) :
         "The logs that the cabin is built out of are thick and sturdy.",   ]) );
   SetExits( ([ 
      "north" : PR_ROOM "/grove2", 
   ]) );
   SetEnters( ([
      "cabin" : PR_ROOM "/cabin",
   ]) );
}

