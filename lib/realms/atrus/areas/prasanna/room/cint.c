#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
  SetDomain("Valley");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("interior of a deep cavern");
   SetLong("The cavern widens out here, into a large chamber devoid of any "
           "sound. Light seems to trickle in from the south, as the "
           "phosphorescent crystals become less abundant here. The chamber "
           "begins to constrict to the north, and looks barely large enough to fit "
           "through.");
   SetItems( ([ 
      ({ "cavern", "cave", "chamber" }) :
         "This cavern is dark and foreboding. ",
      ({ "crystals", "phosphorescent crystals","crystal" }) : 
         "These are small crystals with an unearthly, mysterious glow.",
      ({ "drop", "water" }) : 
         "Tiny drops of water fall from the ceiling once in awhile.",
      ({ "floor", "cavern floor" }) : 
         "The floor here is littered with sedient. ",
   ]) );
   SetExits( ([ 
      "north" : PR_ROOM "/stair", 
      "south" : PR_ROOM "/caventr",
   ]) ); 
   SetListen( ([
      "default" : "The silence is all encompassing, only broken by the occasional "
                    "echo of a drop of water colliding with the cavern floor."
   ]) );
   SetSmell( ([ 
      "default" : "The cavern smells damp and dirty. "
   ]) );
}
