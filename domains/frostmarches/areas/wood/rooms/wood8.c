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
  SetObviousExits("west, northwest");
  SetExits( ([
       "west" : WOOD_ROOMS + "wood7",
       "northwest" : WOOD_ROOMS + "wood10",
       ]) );
  SetLong("Little light penetrates the dense canopy of growth overhead. "
         "Shades of darkness smother what little light does struggle "
         "through. In the dark, the trees become dark, menacing "
         "monsters with outstretched clawing hands. Glowing red eyes "
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
        ({"red eyes","eye", "eyes"}) : "The eyes appear to be those "
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
     ]) );
}
