#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
  SetDomain("Valley");
   SetAmbientLight(25);
   SetShort("a dark stairway");
   SetLong("The stairs continue up for what seems like miles, with only the "
           "occasional glimmer of light from the strange fiery crystals "
           "embedded deep within the walls. The stairs begin to improve, "
           "showing less wear and tear...as if few had come this far.");
   SetItems( ([ 
      ({ "ancient stairway","stairway","steps","step","stairs","stair" }) : 
         "These steps are carved directly into the walls of the cavern, and "
         "continue a dangerous climb straight up.", 
      ({ "walls","wall" }) :
         "Damp and smooth, the walls would be impossible to clime without "
         "the ancient stairway.",      ({ "fiery crystals", "crystals","crystal" }) : 
         "These crystals glow dimly in the darkness, providing little light.", ]) );
   SetExits( ([ 
      "down" : PR_ROOM "/stair",
      "up" : PR_ROOM "/stairtop" 
   ]) );
}

