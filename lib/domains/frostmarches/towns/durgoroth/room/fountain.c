#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("the center of Durgoroth");
  SetLong("Everywhere there are shattered buildings and"
          " blood stains. The horizon is marred by the"
          " asymmetrical remains of the various buildings"
          " and towers that once defined this city. The only"
          " thing left standing here is a metallic fountain."
          " To the east the remains of the library can barely"
          " be made out among all the destruction. The road"
          " can be followed to the west around what was once"
          " the market district and to the east to the"
          " ruins of the library and bank. To the south"
          " the toppled gate of the city can still be seen.");
  SetItems( ([
          ({ "gate" }) :
             "The battered and broken city gate can be seen"
             " to the south.",
          ({ "library", "remains", "horizon", "market" }) :
             "The remains of the various buildings such"
             " as the library and market mar the horizon"
             " with their asymmetrical shapes, providing"
             " a bleak and chaotic appearance to this"
             " desolate ruin.",
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
          ({ "square", "town square" }) :
             "It's obvious that prior to the ruination of"
             " the city, this was once the town square."
             " While debris of all kinds litter the area"
             " a fountain sits defiantly in the center of"
             " the area.",
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
          DURG_OBJ "fountain" : 1,
          DURG_NPC "toughcitizen" : 1,
          DURG_NPC "weakcitizen" : 3,
          DURG_NPC "equipper" : 1,
          DURG_NPC "controller" : 1,      
          ]) );
  SetExits( ([
          "east" : DURG_ROOM "road05",
          "west" : DURG_ROOM "road03",
          "south" : DURG_ROOM "road02",
          ]) );
}
