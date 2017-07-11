/*  The park with the tree.  */

// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../ruins.h"
inherit LIB_CHAPEL;
 
static void create() {
  ::create();
  SetShort("a beautiful park");
  SetClimate("temperate");
  
  SetExits( ([
    "south"   : ROOM "/ruins6",
    "north"   : ROOM "/ruins8",
  ]) );
  
  SetDayLong("Beautiful wildflowers grow in this well tended park.  There "
             "has been alot of effort to keep this park from sliding into "
             "disrepair.  There are large weeds and briars to the north, "
             "west and east ends of a park, blocking those directions.  "
             "An emerald tower and a rosy cathedral shed light to the "
             "north.");

  SetNightLong("This park looks peaceful in the night.  Wild flowers wave "
               "slightly in the light breeze.  To the north there stands "
               "an emerald tower and a rosy catherdral.  Both give off a "
               "bright radiance.  The path to those buildings is blocked by "
               "briars and weeds.");

  SetItems( ([
    ({ "beautiful wildflowers", "beautiful wildflower", "wildflower",
       "wildflowers", "flowers", "flower", "ballet of flowers" })  :
       "Beautiful wildflowers wave slightly in the warm breeze.  The flowers "
       "contain a wide spectrum of colors.  Reds, blues, pinks, yellows, and "
       "oranges dance in ballet of flowers.",
    ({ "tangle of weeds and briars", "tangle of weeds", "tangle of briars",
       "briars", "briar", "weed", "weeds", "large weed", "large weeds" })  :
       "A tangle of weeds and briars surround the park.  They prevent "
       "entry, and exit, from any direction than the south.",
    ({ "large emerald greentower", "emerald green tower", "emerald tower",
       "tower" })   :
       "A large emerald green tower rises to the north.  It gives off a deep "
       "green glow.",
    ({ "green glow", "glow", "green light", "light" })  :
       "A green light radiates from the stones of the tower.",
    ({ "rosy cathedral", "cathedral", "rose cathedral", 
       "majestic cathedral" })   :
       "A majestic cathedral raises its rosy spires to the sky.  The fine "
       "building illuminates the north with a light pink radiance.",
    ({ "light pink radiance", "light pink glow", "glow", "pink radiance",
       "pink glow", "radiance" })   :
       "A light pink glow illuminates the cathedral.",
    ({ "rosy spires", "rosy spire", "spires", "spire" })   :
       "The rosy spires of the cathedral reach toward the sky.",
  ]) );
  SetReligion("Magildan");
  SetSmell( ([
    "default"  : "Spring air fills the garden.",
  ]) );

  SetListen( ([
    "default"  : "A spring breeze whispers through the park.",
  ]) );

  SetInventory( ([
     OBJ "/tree_sapling" :1,
     NPC "/kara" : 1,
  ]) );
}
