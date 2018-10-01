#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetShort("a hallway in the palace");
   SetLong("The hallway stretches for what seems like miles. Arched "
           "windows give a wondrous view of the palace gardens, and "
           "marble sculptures are scattered down the length of the "
           "hallway, giving tribute to the heroes of Prasanna. Midway "
           "down the hall, doors lead off to bedrooms on the north "
           "and south. To the east lies the palace's main hall.");
   SetItems( ([
      ({ "marble sculptures","sculptures","heroes","hero" }) :
         "The sculptures that litter the hallway are beautiful "
         "carvings in marble, depicting heroes of the city.",
      ({ "wondrous view" }) :
         "The view of the gardens out the windows is spectacular and "
         "beautiful.", 
      ({ "walls","wall" }) :
         "The walls of the palace are carved from granite, with marble"
         "overlays to add the appearance of sculpture all along ghout "
         "the palace.",
      ({ "floors","floor" }) :
         "The floors of the palace are polished marble, naturally.",
      ({ "arched windows","windows","window","arches","arch" }) :
         "These sculpted arches add art and beauty to the hallway, "
         "and give a grand view of the palace gardens.",
      ({ "bedrooms","bedroom" }) :
         "These are the rooms of the palace reserved for honored "
         "guests.",
      ({ "long hallway","hallway" }) :
         "This hallway stretches on for quite some way, leading to , "
         "the servants quarters.",
      ({ "main hall","hall" }) :
         "These steps stretch across the entire width of the palace "
         "foyer, yet only a small door leads into the building.",
      ({ "white marble","marble" }) :
         "The white marble that makes up a large portion of the "
         "palace looks as white as ivory, and as smooth and soft "
         "as silk.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm "
         "breeze drifts through the estate, making it seem almost "
         "inviting.",
      ({ "doors" }) :
         "These doorways lead to the guest bedrooms. ",
      ({ "palace gardens","palace garden","gardens","garden" }) :
         "The gardens outside the palace are a vision of beauty, and "
         "are a welcomed sight through the arched windows.",
   ]) );
   SetExits( ([ 
      "east" : PA_ROOM "/estatehall",
      "west" : PA_ROOM "/hallway2", 
      "south" : PA_ROOM "/bedroom2",
      "north" : PA_ROOM "/bedroom1",
   ]) );
   SetSmell( ([ 
       "default" : "The sweet smell of flowers and vegetation drifts "
                     "through the open-air arches here."
   ]) ); 
   SetListen( ([ 
       "default" : "The sounds of birds and running water are easily "
                     "audible from the palace gardens." 
   ]) );
}
