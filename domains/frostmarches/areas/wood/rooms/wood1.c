/* entrance to wood
   Ela 8/3/98
*/

#include <lib.h>
#include <domains.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a dark wood");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("north, west, south, southwest, southeast");
  SetExits( ([
          "north" : FROSTMARCHES_AREAS + "kingdom/rooms/kingdom20",
         "west" : WOOD_ROOMS + "wood2",
         "south" : WOOD_ROOMS + "wood6",
         "southwest" : WOOD_ROOMS + "wood5",
        "southeast" : WOOD_ROOMS + "wood7",
         ]) );

  SetLong("The forest takes on a decidedly sinister cast here. "
         "Little light penetrates the dense growth overhead. "
        "In the shadows, trees become dark menacing monsters "
       "with outstretched, clawing hands. Dense brush litters "
       "the ground, making travel difficult. Glowing red eyes "
       "watch unblinkingly from the shadows.");
  SetItems( ([
          ({"tree","trees","monster","monsters"}) : "Massive trees appear "
                    "monster-like with outstretched, clawing hands.",
          ({"hands","hand","branch","branches","claw","claws"}) : "The "
                   "sharp branches of the trees look like claws in "
                  "the dark.",
         ({"light","sunlight","beam","beams"}) : "The canopy of "
                "the wood allows "
                 "only a few stray beams of sunlight to filter "
                 "through.",
          ({"dense growth","growth","canopy"}) : "The trees form "
               "a dense canopy, shrouding the wood in shadows.",
        ({"shadow","shadows","darkness"}) : "Shadows blanket the "
               "wood in forbidding darkness.",
        ({"red eyes","eye","eyes"}) : "The eyes appear to those "
              "of some wild animal.",
        ({"dark wood","wood","forest","area"}) : "This dark wood "
             "has a distinctly unwelcoming ambiance.",
            ]) );
  SetSmell( ([
        "default" : "Wet earth and pine scents the air.",
        ]) );
  SetListen( ([
        "default" : "The rustling of leaves by unseen creatures "
                   "breaks the silence of the wood.",
       ]) );
  SetInventory( ([
       WOOD_NPC + "boar" : 1,
        ]) );
}
