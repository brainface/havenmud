#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetShort("a hallway in the palace");
   SetLong("This is the western end of the hallway. Two marble "
           "benches sit across from one another, giving a marvelous "
           "view through the arched windows into the garden. To the "
           "west, an ornately carved marble staircase spirals up to "
           "the second level of the palace. A pair of guest bedrooms "
           "lie across from each other, to the north and south. To "
           "the east, the hallway continues on towards the main hall "
           "of the palace.");
   SetItems( ([
      ({ "marble benches","benches","bench" }) :
         "These benches are ideally placed to give people a quiet "
         "place to talk, or simply to gaze into the gardens.",
      ({ "marble staircase","staircase","stairs" }) :
         "This marble staircase is beautifully carved from virgin "
         "white marble. It winds it's way up to the second floor of "
         "the palace.",
      ({ "marvelous view" }) :
         "The view of the gardens out the windows is extraordinarily "
         "romantic and calming.", 
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
         "the servants quarters and guest rooms.",
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
      "east" : PA_ROOM "/hallway",
      "up" : PA_ROOM "/secondfloor", 
      "south" : PA_ROOM "/bedroom4",
      "north" : PA_ROOM "/bedroom3",
   ]) );
   SetSmell( ([ 
       "default" : "The scents of lilac and jasmine mix here, to "
                   "create a lovely fragrance."
   ]) ); 
   SetListen( ([ 
       "default" : "The sounds of birds and running water are easily "
                   "audible from the palace gardens." 
   ]) );
}
