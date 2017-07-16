#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

int PreExit();

static void create() {
   room::create();
   
   SetShort("under a platform");
   SetLong("A number of both pale and rich green plants sprout up "
           "out of the soft ground, unfurling themselves into the "
           "fresh air.  A path marked only by footprints traverses around "
           "the plants in a direct move to the south and northeast, but "
           "one is not blocked from going west if one so chooses.  "
           "A platform is delicately balanced on some dead trees here.");
   SetItems( ([
                ({ "wooden platform","platform" }) :
                   "Dead trees hold up the wooden platform, positioning "
                   "it up in the sky.  It was carefully fashioned to "
                   "last with great strength and endurance, so that "
                   "it would not have to be replaced.",
                ({ "dead trees","dead tree","trees","tree" }) :
                   "The dead trees are the lower halves of some "
                   "trees that were cut up long ago.  The upper halves "
                   "probably went into the platforms that the lower "
                   "halves support.",
                ({ "live trees","live tree","tree","trees","living trees",
                   "living tree" }) :
                   "Living trees surround the area to the north and "
                   "east, growing thick and happy in the sun they "
                   "get, since they don't live under the platform.",
                ({ "plain unadorned path","unadorned path","plain path",
                   "path" }) :
                   "The path meanders to the south and northeast, but "
                   "It stays in straight line.  The dirt beneath it "
                   "is marked with diverse footprints; many races must "
                   "travel along it.",
                ({ "diverse footprints","diverse footprint","footprints",
                   "footprint","prints","print" }) :
                   "The footprints have packed the dirt of the path down "
                   "more than the surrounding ground, making it stand "
                   "out.  No plants grow on the path, either, so the "
                   "prints are easier to pick out.  The footprints "
                   "of almost all the races are present; one looks almost "
                   "as if an orc made it!",
                ({ "pale and rich green plants","pale green plants",
                   "pale plants","green plants","pale green plant",
                   "pale plant","green plant","rich green plants",
                   "rich plants","rich plant","plants","plant" }) :
                   "Most of the pale plants hang out far under the "
                   "platform, where the least sun goes.  They are "
                   "shorter and have had much less chance to grow, "
                   "compared to the plants towards the edges, hiding "
                   "under the living trees.  Those are of a richer, "
                   "healthier color.",
                ({ "soft ground","ground","dirt","soft dirt" }) :
                   "The dirt has been stirred up nicely, and "
                   "makes a fertile area for plants to grow in.  "
                   "In fact, currently, a lot of plants are growing "
                   "in it.",
           ]) );
   SetListen( ([
                 "default" : "A breeze rushes through the trees, and "
                    "carries down the noisy laughter from above.",
            ]) );
   SetSmell( ([
                "default" : "Odors arise from the soft dirt.",
                "dirt" : "The dirt smells rich and fertile.",
           ]) );
   SetExits( ([
                "northeast" : M_ROOM + "path",
                "south"     : M_ROOM + "ground_f",
           ]) );
   AddExit("west",M_ROOM + "ground_b",(: PreExit :));
   SetInventory( ([
                    M_NPC + "trav_wor" : 1,
                    M_NPC + "monk_h" : 2,
                    M_NPC + "monk_c" : random(2)+2,
               ]) );
}

int PreExit() {
   if(this_player()->GetProperty("monasterynoleave")) return 0;
   return 1;
}
