
#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("a dark and broken path leading into Durgoroth");
  SetLong("Scattered all around are the remains of buildings"
          " and gates. Wood, masonry, metal, all litter the"
          " ground providing unsteady footing for the weary"
          " traveler. To the east the battered shell of"
          " what was once an inn can be seen while the west"
     
     " is obscured by large boulders that once stood"
          " mightily as the city wall. Not far to the north"
          " a fountain and what looks to be a town square"
          " can be seen, while to the south the road leads"
          " away from the ruins of Durgoroth.");
  SetItems( ([
          ({ "buildings", "ruins" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. They appear"
             " to have been blasted apart from the insides"
             " scattering masonry wood and metal all around.",
          ({ "wood", "masonry", "metal", "debris", "litter" }) :
             "The debris that litters the ground is of varying"
             " shapes, sizes, and materials. It covers"
             " everything making it difficult to navigate"
             " through the ruins.",
          ({ "inn", "boulders", "wall", "city wall", "shell" }) :
             "To the east and west the path is obscured by the"
             " ruins of an inn and the city wall, respectively.",
          ({ "fountain", "square", "town square" }) :
             "To the north what appears to have been a town"
             " square is visible. A fountain still sprays"
             " a liquid of sorts into the air.",
          ]) );
  SetSmell( ([ 
          "default" : "All throughout this area the smell"
          " of dried blood permeates.", 
          ]) );
  SetListen( ([ 
          "default" : "The distant rustling of survivors"
          " picking through the ruins can be heard", 
          ]) );
  SetInventory( ([
          DURG_NPC "toughcitizen" : 2,
          ]) );
  SetExits( ([
          "north" : DURG_ROOM "fountain",
          "south" : DURG_ROOM "road01",
          ]) );
}
