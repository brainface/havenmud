#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("west of the fountain in Durgoroth");
  SetLong("The area here is pretty clean with minimal"
          " debris obstructing passage. The remains"
          " of an inn lie to the south while to the"
          " east the fountain can be seen. A large"
          " pile of rubble makes passage to the"
          " northeast impossible but if one were"
          " so inclined, the way north has been"
          " cleared enough to provide passage.");
  SetItems( ([
          ({ "buildings", "ruins", "inn", "building", "ruin" }) :
             "The ruins of an inn stand along the south end"
             " of the road here. It appears to be enterable"
             " despite it's current state.",
          ({ "wood", "masonry", "metal", "debris", "litter" }) :
             "The debris that litters the ground is of varying"
             " shapes, sizes, and materials. There is very"
             " little of it here, however.",
          ({ "square", "town square", "fountain" }) :
             "To the east the town square and fountain can"
             " be seen.",
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
          DURG_NPC "trainer" : 1,
          DURG_NPC "shopkeep" : 1,
          ]) );
  SetExits( ([
          "east" : DURG_ROOM "fountain",
          "north" : DURG_ROOM "road04",
          ]) );
  SetEnters( ([
          "inn" : DURG_ROOM "inn",
          ]) );
}
