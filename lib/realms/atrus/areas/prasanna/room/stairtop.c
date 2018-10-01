#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
  SetDomain("Valley");
   SetAmbientLight(35);
   SetShort("top of a dark stairway");
   SetLong("The stairway begin to level off slowly, and light bleeds in from "
           "what appears to be the top of the seemingly endless flight of "
           "stairs. At the top of the last step, the remains of decaying "
           "skeleton guard the exit from the small cave. A mild breeze blows "
           "in through the entrance, yet doesn't seem to stir even a grain "
           "of dust. ");

   SetItems( ([ 
      ({ "stairs", "stairway","steps","step","stairs","stair" }) : 
         "These steps are carved directly into the walls of the cavern, and "
         "continue a dangerous climb straight up.",
      ({ "skeleton","remains" }) : 
         "This skeleton lies haphazardly against the wall of the cave.",
      ({ "walls","wall" }) :
         "The walls of the cave look to have been carved long ago.",
      ({ "entrance" }) :
         "The entrance of the cave is a mere crack in the wall, barely large "
          "enough to fit through.",   ]) );
   SetExits( ([ 
      "out" : PR_ROOM "/cliff", 
      "down" : PR_ROOM "/stair2" 
   ]) );
   SetSmell(([ 
      "default" : "The air begins to smell clean and fresh." 
   ]) );
}

