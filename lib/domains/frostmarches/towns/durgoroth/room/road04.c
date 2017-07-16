
#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("the northwest quadrant of Durgoroth");
  SetLong("The road is barely distinguishable here. The"
          " destruction of the once mighty city is appparent"
          " here as all around are the hollowed remains of"
          " buildings. Off to the northeast a large cave"
          " mouth can been seen with a hint of light"
          " shining out of it. A huge pile of rubble"
          " blocks the way to the east and to the west"
          " the remains of the once mighty city wall"
          " prevents passage to the west. To the south"
          " there looks to be a fairly intact building.");
  SetItems( ([
          ({ "building" }) :
             "To the south a fairly intact building lingers"
             " on the horizon.",
          ({ "rubble", "pile", "Wall" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. A huge pile"
             " of rubble has been amassed to the east making"
             " passage impossible in that direction. While"
             " the remains of the city wall block the way"
             " to the west.",
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
          DURG_NPC "toughcitizen" : 1,
          DURG_NPC "weakcitizen" : 3,
          DURG_NPC "zerker_trainer" : 1,
          ]) );
  SetExits( ([
          "northeast" : DURG_ROOM "road09",
          "south"     : DURG_ROOM "road03",
          ]) );
}

