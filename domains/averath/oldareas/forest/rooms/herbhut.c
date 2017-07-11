// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("inside an orderly hut");
   SetLong("Well-organized shelves line the walls above the dirt floor.  "
           "Many plants dry on the ceiling, hanging up-side down as they "
           "slowly wither.  A crimson curtain hangs over an opening in "
           "the hut.");
   SetItems( ([
                ({ "orderly hut","hut" }) : (: GetLong :),
                ({ "well-organized shelves","shelf","shelves" }) :
                   "Glass jars cover the sturdy wooden shelves.",
                ({ "glass jars","jars","jar","glass" }) :
                   "Sitting in an organized manner on the wooden shelves, "
                   "the glass jars contain a variety of plants in "
                   "a plethora of stages.",
                ({ "jarred plants","plants","plant" }) :
                   "The plants in the jars come in many stages of life.  "
                   "Some are young, new shoots and others are dried "
                   "flakes.",
                ({ "dirt floor","floor","dirt" }) :
                   "Packed dirt forms the floor of the hut.",
                ({ "walls","wall","ceiling" }) :
                   "The walls were made of strong wood, lovingly crafted "
                   "into this hut.",
                ({ "drying plants","plant","plants" }) :
                   "Many different plants are set out to dry, hanging "
                   "from the ceiling.  They slowly wither until all the "
                   "life is gone from them.",
                ({ "crimson curtain","curtain" }) :
                   "Over the opening and only exit from the hut hangs a "
                   "deep scarlet-shaded curtain.  The wind blows at it "
                   "gently, creating small waves in the fabric.",
           ]) );
   SetSmell( ([
                "default" : "A delightful peppermint scent fills the hut.",
                "drying plants" : "Some of these plants must be mint, as "
                   "a strong mint smell exudes from them.",
           ]) );
   SetListen( ([
                 "default" : "The wind blows outside.",
            ]) );
   SetExits( ([
                "out" : AVERATH_ISLAND + "9,-4,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "herbalist" : 1,
               ]) );
}
