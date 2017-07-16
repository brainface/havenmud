
// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISHING;

static void create() {
   ::create();
   SetShort("on the beach");
   SetLong("The beach meanders to the east and south, with the sea "
           "expanding to the southeast.  A towering cliff blocks "
           "all other exits.  A few flat rocks splattered with blood "
           "adorn the beach.");
   SetItems( ([
                ({ "beach" }) : (: GetLong :),
                ({ "sea","ocean","waves","wave","water" }) :
                   "The water rolls against the beach.",
                ({ "towering cliff","cliff" }) :
                   "The cliff raises at least 5 to 7 human males high.",
                ({ "flat rocks","rocks","rock" }) :
                   "Three flat rocks rest in a clust on the beach, "
                   "stained with splashes of red.",
                ({ "fish blood","blood" }) :
                   "The blood stains the rocks, probably from gutting " 
                   "fish.",
           ]) );
   SetItemAdjectives( ([
                         "cliff" : ({ "towering" }),
                         "rocks" : ({ "flat","bloody" }),
                    ]) );
   SetSmell( ([
                "default" : "A rancid fish smell hangs in the air.",
                "blood" : "The blood has a poignent, unpleasant scent.",
                "rocks" : "The rocks don't smell so much as the blood does.",
           ]) );
   SetListen( ([
                 "default" : "The ocean roars.",
                 "ocean" : "The ocean crashes against the rocks.",
            ]) );
   SetExits( ([
                "south" : AVERATH_ISLAND + "9,-6,0",
                "east" : AVERATH_ISLAND + "10,-5,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "fisherwoman" : 2,
               ]) );
  SetSpeed(2);
  SetFish( ([
              FOREST_OBJ + "sockeye" : 10,
              FOREST_OBJ + "chum" : 200,
              FOREST_OBJ + "dogshark" : 1,
         ]) );
  SetChance(55);
  SetMaxFishing(50);
}
