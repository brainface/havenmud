/* a dark wood
    Ela 10/12/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a dark wood");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("north, northwest, west, east, northeast");
  SetExits( ([
        "north" : WOOD_ROOMS + "wood1",
        "west" : WOOD_ROOMS + "wood5",
        "east" : WOOD_ROOMS + "wood7",
       "northeast" : WOOD_ROOMS + "wood10",
        "northwest" : WOOD_ROOMS + "wood2",
        ]) );
  SetLong("The menacing atmosphere of the wood is stifling. Shades of "
         "of darkness blanket the area. The dense canopy above allows "
         "little light to penetrate the shadows. The oversized trees "
         "look alive and threatening in the gloom. Glowing red eyes "
         "watch unblinkingly from the shadows.");
  SetItems( ([
         ({"tree","trees","monster","monsters"}) : "Massive trees appear "
                   "monster-like with outstretched, clawing hands.",
         ({"hands","hand","branch","branches","claw","claws"}) : "The "
                   "sharp branches of the trees look like claws in "
                   "the dark.",
         ({"light","sunlight","beam","beams"}) : "The canopy of "
                   "the wood allows only a few stray beams of sunlight "
                   "to filter through.",
         ({"dense growth","growth","canopy"}) : "The trees form "
                   "a dense canopy, shrouding the wood in shadows.",
         ({"shadow","shadows","darkness","gloom"}) : "Shadows blanket the "
                  "wood in forbidding darkness.",
         ({"red eyes","eye","eyes"}) : "The eyes appear to be those "
                   "of some wild animal.",
         ({"dark wood","wood","forest","area"}) : "This dark wood "
                   "has a distinctly unwelcoming ambiance.",
           ]) );
  SetSmell( ([
          "default" : "The air carries a heavy woodsy smell.",
          ]) );
  SetListen( ([
          "default" : "Rustling leaves and stirring brush can be heard.",
          ]) );
  SetInventory( ([
      WOOD_NPC + "boar" : 3,
       ]) );
}
