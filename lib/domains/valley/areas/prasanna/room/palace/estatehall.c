#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("main hall of the royal palace");
   SetLong("The main hall of the palace is, simply put, gargantuan. "
           "The entire room is floored with white marble, with matching "
           "pillars running down the length of the room. Masterfully "
           "created silk tapestries hang on the east and west walls, "
           "falling nearly to the floor. To the north, a large "
           "archway leads to the throne room. To the west, a long "
           "hallway leads to other parts of the palace. To the south "
           "another doorway leads out into the gardens.");
   SetItems( ([ 
      ({ "walls","wall" }) :
         "The walls of the palace are carved from granite, with marble "
         "overlays to add the appearance of sculpture all along throughout "
         "the palace.",
      ({ "floors","floor" }) :
         "The floors of the palace are polished marble, naturally.",
      ({ "archway","arch" }) :
         "This sculpted archway winds around two pillars, and marks the "
         "entrance to the throne room of Maeralin.",
      ({ "throne room" }) :
         "The archway leads to the throne room of Maeralin.",
      ({ "long hallway","hallway" }) :
         "This hallway stretches for quite a distance to the west, "
         "leading to the servants and guests quarters.",
      ({ "main hall","hall" }) :
         "These steps stretch across the entire width of the palace "
         "foyer, yet only a small door leads into the building.",
      ({ "white marble","marble" }) :
         "The white marble that makes up a large portion of the palace "
         "looks as white as ivory, and as smooth and soft as silk.",
      ({ "silk tapestries","silk tapestry","tapestries","tapestry" }) :
         "These tapestries are easily fifty feet long and fifteen "
         "feet wide. They depict scenes that would appear to be the "
         "birth of the city. ",
      ({ "marble columns","columns" }) :
         "The columns are pure marble, carved by hand. The size and "
         "skill required are almost unimaginable.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm breeze "
         "drifts through the estate, making it seem almost inviting.",
      ({ "doorway" }) :
         "These doorways lead to various parts of the palace. ",
      ({ "scenes","scene" }) :
         "The scenes on the various tapestries seem to show a brief history "
         "of the city, mages of various races coming together to create "
         "the city and it's surroundings, then sealing the tunnel to the "
         "city, and finally isolating the city from time itself.",
      ({ "gardens","garden" }) :
         "The gardens outside the palace are a vision of beauty, and are "
         "just barely visible out the doorway to the south. ",
   ]) );
   SetExits( ([ 
      "north" : PA_ROOM "/throne",
      "west" : PA_ROOM "/hallway", 
      "out" : PA_ROOM "/estatefoyer",
   ]) ); 
}
