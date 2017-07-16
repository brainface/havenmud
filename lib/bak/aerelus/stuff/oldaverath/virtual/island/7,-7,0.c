// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISHING;

static void create() {
   ::create();
   SetShort("on the coast");
   SetLong("The ocean crashes against the beach from the east and south, "
           "pushing up to the edge of the tide line.  The sea cliffs stand "
           "above, towering into the sky as a sheer rock face.  The beach "
           "follows the edge of the sea cliffs, continuing to the northeast "
           "and west.");
   SetItems( ([
                ({ "coast" }) : (: GetLong :),
                ({ "ocean","water" }) : "The ocean is a huge body of salty water.",
                ({ "beach" }) : "The beach continues to the northeast and west, "
                   "keeping close to the edge of the sea cliffs.",
                ({ "tide line","seaweed","driftwood","wood" }) :
                   "Formed by the waves pushing ocean waste as far up the beach "
                   "as possible, the tide line contains rotting seaweed and "
                   "driftwood that is falling apart.",
                ({ "sea cliffs","cliff","cliffs" }) :
                   "The sea cliffs tower into the sky above, terminating about "
                   "five adult humans high.",
           ]) );
   SetItemAdjectives( ([
                         "tide line" : ({ "rotting","tide" }),
                         "cliffs" : ({ "sea" }),
                    ]) );
   SetSmell( ([
                "default" : "The ocean's odor permeates the beach.",
           ]) );
   SetListen( ([
                 "default" : "Seagulls screech loudly over the waves.",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "beachcomber" : 3,
                    FOREST_NPC + "seagull" : 4,
               ]) );
   SetExits( ([
                "northeast" : AVERATH_ISLAND + "8,-6,0",
                "west" : AVERATH_ISLAND + "6,-7,0",
                "south" : INNERSEA_VIRTUAL "ocean/7,-113",
                "east"  : INNERSEA_VIRTUAL "ocean/8,-112",
           ]) );
  SetProperty("coastal", 1);         
  SetSpeed(2);
  SetFish( ([
              FOREST_OBJ + "sockeye" : 5,
              FOREST_OBJ + "chum" : 200,
              FOREST_OBJ + "dogshark" : 30,
         ]) );
  SetChance(55);
  SetMaxFishing(50);

}
