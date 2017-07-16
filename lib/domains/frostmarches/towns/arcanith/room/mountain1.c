/*  A mountain trail leading to the ruins - made by Sardonas */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail up the mountain");
  SetClimate("arctic");
  
  SetExits(  ([
     "north"    : ROOM "/mountain2",
     "south"  : ROOM "/path7",
  ]) );
 
  SetDayLong("This small trail leads up the mountain.  It looks like it "
             "may have been made by mountain goats. Stunted pine trees "
             "and snow cling to the edge of the mountain.  The silver glow "
             "is barely visible.");

  SetNightLong("The small trail appears very dangerous in the darkness.  "
               "It doesn't seem that wide and the stones seem very loose.  "
               "The shadowed pine trees are barely visible in the night.  "
               "The silver glow from above lights the way like a beacon.");
 
  SetItems( ([
    ({ "small trail", "trail" })  :
       "This small trail snakes up the mountain.  The only thing that could "
       "possibly climb this trail are mountain goats or adventurers.  The "
       "terrain is covered in a layer of snow.",
    ({ "frozen tundra", "icy tundra", "tundra" })  :
       "The icy tundra below is fairly featureless.  Snow covers everything.",
    ({ "thick layer of hard-packed snow", "thick layer of snow", 
       "layer of hard-packed snow", "hard-packed snow", "hard snow", "snow",
       "layer of snow" })  :
       "A thick layer of hard-packed snow covers everything fo miles.",
    ({ "mountain" })  :
       "The mountain towers over the frozen tundra.  It climbs into the air.",
    ({ "stunted pine tree", "trees", "pine trees", "tree", "pine tree",
       "stunted pine trees", "small pine tree", "small pine trees", 
       "stunted, pine trees", "stunted, pine tree", "evergreens",
       "evergreen"  })  :
       "Small pine trees and evergreens cling to the steep mountain.",
    ({ "silvery glow", "glow", "silver glow", "silver light", "beacon" })  :
       "The silver glow from above sheds a silver light into the sky.",
    ({ "small sharp stones", "small sharp stone", "sharp stones",
       "stones", "stone", "small stone", "small stones", "sharp stone" }) :
      "Small sharp stones lie loosely on the mountain.  They begin to slide "
       "down the mountain at the slightest touch.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells of dirt and stone.  The smell of pine "
                 "hangs heavy in the air.",
  ]) );
 
  SetListen( ([
    "default"  : "The clicking of falling rocks fills the air.",
  ]) );
}
