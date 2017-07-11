#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the servants quarters");
   SetLong("These are the living quarters of some of the palace "
           "servants. While they do appear lived in, they are "
           "currently not occupied. The quarters are lavish to the "
           "extreme. Fine linens lie seemingly untouched upon "
           "the beds, and the furnishings are fit for royalty. On "
           "the far side of the room, large windows look out over "
           "the gardens. The exit lies back to the north. ");
   SetItems( ([
      ({ "large windows","windows","window" }) :
         "Large windows carved out of the polished granite overlook "
         "the gardens, and circulate fresh air through the room.",
      ({ "living quarters","quarters" }) :
         "These are the quarters of the palace servants.",
      ({ "palace servants","servants" }) :
         "The servants are volunteers which have devoted their lives "
         "to keeping the palace a beautiful place.", 
      ({ "walls","wall" }) :
         "The walls of these bedrooms are polished granite, decorated "
         "as their occupants see fit.",
      ({ "floors","floor" }) :
         "The floors of the palace are polished marble, naturally.",
      ({ "fine linens","linens","fine linen","linen" }) :
         "The bedcoverings are made of light silk, yet are more than "
         "adequate for the warm climate.",
      ({ "beds","bed" }) :
         "Two servants share these quarters, both beds are elaborate "
         "and look sinfully comfortable.",
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
      "north" : PA_ROOM "/hallway",
   ]) );
   SetSmell( ([ 
       "default" : "The scent of fresh air and flowers drifts through "                    
                     "the room."
   ]) ); 
}

