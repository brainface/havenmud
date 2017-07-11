/* This is the eleventh room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../beach.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("the dropoff to the sea");
  SetSmell( ([ 
    "default" : 
    "The smell of salt is very strong while standing in this water." 
    ]) );
  SetListen( ([ 
    "default" : 
     "The crashing of the waves along the shore can be heard in the distance." 
     ]) );
  SetInventory( ([
    BEACH_NPC + "fish" : 4,
    BEACH_NPC + "swan" : 1,
    ]) );
    SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
  SetLong( 
    "While standing out past the shore, the depths of the sea "
    "can be seen while peering straight down into the cold "
    "waters. This cliff holds solid, but is rather close to the "
    "dropoff into the sea." );
  SetItems( ([
    ( { "dropoff", "cliff" } ) : 
    "This cliff is at the very edge of any shallow water.",
    ( { "sea", "water", "waters" } ) : 
    "The dark waters of the sea are rough.",
    "salt" : "The salt is invisible in this water.",
    "waves" : "These giant waves cover the sea.",
    "shore" : "The sandy beach here goes for miles.",
    ( { "beach", "sandy beach" } ) : 
    "This is the edge of the sand and the water.",
    ]) );
  SetClimate("temperate");
  SetExits( ([
    "west"      : BEACH_ROOM "beach10",
    "northeast" : BEACH_ROOM "beach12",
    "south"     : INNERSEA_VIRTUAL "ocean/10,33",
    "east"      : INNERSEA_VIRTUAL "ocean/11,34",
    "southeast" : INNERSEA_VIRTUAL "ocean/11,33",
    ]) );

}
