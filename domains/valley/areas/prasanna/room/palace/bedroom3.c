#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetShort("a guest bedroom");
   SetLong("This bedroom is quite large, and is strikingly similar "
           "to it's twin across the hall. Large pillows lie around "
           "the room to serve as seating, and against the far wall, "
           "between two large open air windows, lies a beautiful "
           "canopy bed. An oak vanity sits near the east wall, with "
           "a matching chair. These quarters are quite obviously for "
           "honored guests and visiting diplomats. To the south is  "
           "a door back into the hallway.");
   SetItems( ([
      ({ "large windows","windows","window","open air windows" }) :
         "Large windows carved out of the polished granite overlook "
         "the gardens, and circulate fresh air through the room.",
      ({ "guest quarters","quarters" }) :
         "These are rooms reserved for honored guests.",
      ({ "walls","wall" }) :
         "The walls of these bedrooms are polished granite, decorated "
         "as their occupants see fit.",
      ({ "floors","floor" }) :
         "The floors of the palace are polished marble, naturally.",
      ({ "canopy bed","bed" }) :
         "This canopy bed is marvelously carved from light oak, and "
         "has posts which rise seven feet into the air, and suspend "
         "a veil of thin, sheer silk.",
      ({ "oak vanity","vanity" }) :
         "This piece of furniture is hand carved from solid oak, and "
         "has a number of drawers for storing clothing and such.",
      ({ "white marble","marble" }) :
         "The white marble that makes up a large portion of the "
         "palace looks as white as ivory, and as smooth and soft "
         "as silk.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm "
         "breeze drifts through the estate, making it seem almost "
         "inviting.",
      ({ "doors" }) :
         "These doorways lead back out into the hallway. ",
      ({ "palace gardens","palace garden","gardens","garden" }) :
         "The gardens outside the palace are a vision of beauty, and "
         "are a welcomed sight through the arched windows.",
   ]) );
   SetExits( ([ 
      "south" : PA_ROOM "/hallway2",
   ]) );
   SetSmell( ([ 
       "default" : "The room smells clean and the scent of freshly "
                   "laundered linen fills the air.",
   ]) ); 
}
