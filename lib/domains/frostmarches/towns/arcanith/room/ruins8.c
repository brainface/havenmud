/* Path north of the Park - by Sardonas */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("north of the park");
  SetClimate("temperate");
  SetNightLight(10);
  SetExits( ([
     "south"  : ROOM  "/park"
  ]) );

  SetDayLong("The ravages of time have greatly affected the area north of "
             "the park.  Creeping vines break up the path leading to the "
             "next tier of the city.  Upon on the next tier of the city lie "
             "two grand buildings.  To the northeast stands a grand "
             "cathedral which appears to be constructed of white marble and "
             "rose quartz crystals.  The sun shines through the quartz and "
             "sends out beautiful rose rays of light.  To the north east looms "
             "a large green tower that seems to be forged of a solid piece of "
             "emerald.  The tower rises high into the air and gives off an "
             "eerie green glow.  Directly north, over the edge of the tier, "
             "some large towers and ramparts can be seen.  What they're "
             "connected to remains unsure.");
  SetNightLong("The ravages of time have greatly affected the area north of "
               "the park.  Creeping vines break up the path leading to the "
               "next tier of the city.  Upon on the next tier of the city lie "
               "two grand buildings.  To the northeast stands a grand "
               "cathedral which appears to be constructed of white marble and "
               "rose quartz crystals.  The sun shines through the quartz and "
               "sends out beautiful rose rays of light.  To the north east looms "
               "a large green tower that seems to be forged of a solid piece of "
               "emerald.  The tower rises high into the air and gives off an "
               "eerie green glow.  Directly north, over the edge of the tier, "
               "some large towers and ramparts can be seen.  What they're "
               "connected to remains unsure.");

  SetItems( ([
    ({ "area" })   :
       (: GetLong :),
    ({ "path" })   :
       "The path north of the park is crumbling due to age and the work of "
       "creeping vines.",
    ({ "tower", "green tower" })   :
       "A large emerald green tower rises to the north.  It gives off a deep "
       "green glow.",
    ({ "glow", "green glow", "green light", "light" })  :
       "A green light radiates from the stones of the tower.",
    ({ "cathedral" })   :
       "A majestic cathedral raises its rosey spires to the sky.  The fine "
       "building illuminates the north with a light pink radiance.",
    ({ "glow", "pink glow", "radiance", "pink radiance" })   :
       "A light pink glow illuminates the cathedral.",
    ({ "spires", "spire" })   :
       "The rosey spires of the cathedral reach toward the sky.",
    ({ "rampart", "ramparts" }) :
      "Ramparts interpersed with several large towers rise to the north, along "
      "the edge of the tier.",
  ]) );


  SetSmell( ([
    "default"  : "The scent of the ages fills this area.",
  ]) );

  SetListen( ([
    "default"  : "The whispering wind rustles the leaves of the park.",
  ]) );
  SetInventory( ([
    NPC "/silvana" : 1,
    ]) );

}
