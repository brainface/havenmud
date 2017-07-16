#include <lib.h>
#include <domains.h>
#include "../path.h"

inherit LIB_ROOM;


static void create() {
  room::create();
  SetClimate("outdoors");
  SetShort("among the boulders");
  SetLong( "A narrow ledge runs along the edge of one of the larger boulders "
           "leading from a breakdown of small boulders, that can be ascended "
           "to reach the top, to a deep crack formed by other boulders piled "
           "against this one.  Shallow water laps against the rocks a few "
           "feet beneath the ledge." );

  SetItems( ([ "ledge" : "The ledge is just wide enough to walk comfortably "
                         "on and leads around the boulders disappearing into "
                         "a dark crack.",
               "water" : "Sea water in an area protected from the waves of "
                         "the sea laps against the stone, a few feet below "
                         "the ledge.",
               "crack" : "The crack is mostly hidden by shadows.",
               "breakdown" : "Small rocks are piled (almost orderly) in one "
                             "of the junctures of two boulders, providing "
                             "a way back to the top of the hill.",
               "swamp" : "The swamp extends for several miles to the south, "
                         "although it only looks traversable on foot for a "
                         "short distance due to the greater depth of water "
                         "to the south.",
               ({"rocks","boulders"}) :
                         "Many of the boulders are near the size of small "
                         "houses."]) );

  SetSearch( ([ "crack" : "The crack gets wider towards the back."]));

  SetExits( ([ "up"    : GWONISH + "room/swamp24",
   						 "south" : INNERSEA_VIRTUAL "ocean/-97,-2",
  						 ]) );

  SetEnters( ([ "crack" : GWONISH + "room/swamp26"]));

  SetSmell( ([ "default" : "A thick briny smell fills your nose."]) );
  SetListen( ([ "default" : "The endless roar of the surf vibrates the "
                   "rocks around you." ]) );
  SetObviousExits("up");
}

