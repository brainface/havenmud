/* The plateau.  It could be a stage for other areas */
/* of the mountain.  The first view of the ruins.    */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a mountain plateau");
  SetClimate("arctic");
  
  SetNightLight(15);
  SetExits( ([
    "north"  : ROOM "/ruins1",
    "south"   : ROOM "/mountain4",
  ]) );

  SetDayLong("The view upon the plateau is breathtaking.  Sprawled across the "
             "northern part of the plateau are ruins, the ruins of a city.  "
             "The ruins are surrounded by a large wall that is broken in "
             "areas.  The mysterious silver glow is radiated by the very "
             "walls of the ruins.");

  SetNightLong("The view before you is temporarily blinding.  A huge city of "
               "light lies upon the northern part of the plateau.  A large "
               "wall of silvery light seems to surround the city.  Upon "
               "closer inspection it appears that the city is in ruins.");

  SetItems( ([
    ({ "city of light", "ruins", "ruins of a city", "huge city of light",
       "city", "city ruins" })  :
       "The ruins of a great city lie upon this plateau.  The view is "
       "breathtaking.  Ruins rise up the mountain, it seems that "
       "the city was built upon different layers, or tiers.  The ruins "
       "are enveloped in a silver glow.",
    ({ "walls of silvery light", "wall of silvery light", "walls of light",
       "wall of light", "walls", "wall", "walls of the ruins", 
       "large walls" }) :
       "The wall surrounding the ruins seems to be made of pure light.  "
       "It is broken in places, where the walls have crumbled.",
   ({ "silvery light", "silver light", "silver glow", "pure light",
      "light" })  :
      "A silver glow illumines the city ruins.  The light seems to radiate "
      "from the walls around the city.",
   ({ "view" })  :
      "The ruins of a city lie upon the plateau and seem to crawl up the "
      "mountain.  Down the mountain, the tundra covers everything for miles.  "
      "The snow and ice causes the ground to sparkle like diamonds.",
   ({ "down the mountain" })  :
      "The tundra covers everything for miles.  The snow and ice causes the "
      "ground to sparkle like diamonds.",
   ({ "icy tundra", "tundra" })   :
      "The icy tundra lies down around the mountain.  The tundra seems to "
      "sparkle like diamonds.",
   ({ "sparkle", "diamonds", "ice and snow", "snow", "ice" })   :
      "The ice and snow of the tundra sparkles when the light hits it.  "
      "It looks almost like the tundra is covered in diamonds.",
   ({ "layers", "tiers", "layer", "tier" })  :
      "The city was made to look like it rises up the mountain.  It appears "
      "the the city was designed into different layers, like a cake.",
  ]) );

  SetSmell( ([
    "default"  : "The air smells of old, forgotten things.  A hint of spring "
                 "waves throught the air.",
  ]) );

  SetListen( ([
    "default"  : "The whisper of a wind is the only sound on the plateau.",
  ]) );

  SetInventory( ([
     NPC "/mountain_goat" : 1 ]) );
}
