#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("the northeast quadrant of Durgoroth");
  SetLong("The road is barely distinguishable here. The"
          " destruction of the once mighty city is appparent"
          " here as all around are the hollowed remains of"
          " buildings. Off to the northwest a large cave"
          " mouth can been seen with a hint of light"
          " shining out of it. Eastward, a nearly intact"
          " building can be made out along the horizon, while"
          " a huge pile of rubble blocks the way to the west.");
  SetItems( ([
          ({ "building", "remains", "horizon", "towers" }) :
             "The remains of the various buildings such"
             " as the library and towers mar the horizon"
             " with their asymmetrical shapes, providing"
             " a bleak and chaotic appearance to this"
             " desolate ruin. To the east, however, one"
             " building looks to have survived nearly"
             " intact.",
          ({ "rubble", "pile" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. A huge pile"
             " of rubble has been amassed to the west making"
             " passage impossible in that direction.",
          ({ "wood", "masonry", "metal", "debris", "litter" }) :
             "The debris that litters the ground is of varying"
             " shapes, sizes, and materials. It covers"
             " everything making it difficult to navigate"
             " through the ruins.",
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
          DURG_NPC "weakcitizen" : 3,
          DURG_NPC "toughcitizen2" : 1,
          ]) );
  SetExits( ([
          "northwest" : DURG_ROOM "road09",
          "east" : DURG_ROOM "road07",
          "south" : DURG_ROOM "road05",
          ]) );
}

