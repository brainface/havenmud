// Amelia

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("near the sea cliffs");
   SetLong("The towering sea cliffs overhang this area, sheltering "
           "it from some of the elements.  A line of seaweed and "
           "driftwood appears near the base of the cliff, where "
           "rocks smoothed by centuries of waves form small "
           "tide pools.  The beach meanders beside the cliffs "
           "to the east and southwest.");
   SetItems( ([
                ({ "beach" }) : (: GetLong :),
                ({ "sea cliffs","cliffs","cliff" }) :
                   "Worn away by the relentless pounding of the "
                   "ocean, the sea cliffs jut out over the "
                   "rocky shore.  Indentations in the cliffs hold "
                   "small pockets of dirt that allow weeds and "
                   "tiny trees to flourish.",
                ({ "small pockets of dirt","dirt","pockets","pocket",
                   "indentations","indentation" }) :
                   "The rough features of the cliff allowed dirt "
                   "to slowly collect, and seeds eventually "
                   "formed plants there.",
                ({ "tiny trees","trees","tree","birch","birches" }) :
                   "Tiny birch trees grow in some of the indentations "
                   "in the sea cliffs.  None are more than half a "
                   "meter tall.",
                ({ "weeds","weed","plants","plant","dandelions",
                   "dandelion","grass" }) : 
                   "Weeds like dandelions and grass grow easily in "
                   "the small pockets of dirt on the sea cliffs.",
                ({ "tide line","seaweed and "
                   "driftwood","seaweed","driftwood",
                   "wood","waste" }) :
                   "The tide line has formed close to the base of the sea cliffs, "
                   "leaving no more than half a meter of space.  Dry brown seaweed "
                   "and smooth, slowly rotting pieces of driftwood form most of "
                   "the conglomeration of ocean waste.",
                ({ "rocky shore","rocks","rock","shore" }) :
                   "Smoothed rocks cover the shore, mingling with the rotting "
                   "driftwood and seaweed.",
                ({ "tide pools","pools","pool" }) :
                   "Pools of ocean water form and reform with every new tide, "
                   "trapping creatures in shallow isolation.",
           ]) );
   SetItemAdjectives( ([ 
                         "dirt" : ({ "small","pocket","pockets","of" }),
                         "birch" : ({ "tiny","birch" }),
                         "cliffs" : ({ "sea","towering" }),
                         "rocks" : ({ "smoothed" }),
                         "pools" : ({ "small","tide","tidal" }),
                         "tide line" : ({ "dry","brown","smooth","slowly","rotting",
                                          "pieces","piece","of","ocean" }),
                    ]) );
   SetSmell( ([
                "default" : "The salty scent of the ocean overpowers "
                   "all other odors.",
           ]) );
   SetListen( ([
                 "default" : "The waves beat against the rocky shore.",
            ]) );
   SetExits( ([
                "east" : AVERATH_ISLAND + "9,-6,0",
                "southwest" : AVERATH_ISLAND + "7,-7,0",
                "south"     : INNERSEA_VIRTUAL "ocean/8,-112",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "seagull" : 2,
                    FOREST_NPC + "beachcomber" : 1,
               ]) );
}
