#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"
#define MAYLEAVE 1

int PreExit();
#define OUT "/domains/westwood/virtual/soleilroad/0,20"

static void create() {
   room::create();
   SetDomain("WestWood");
   SetShort("in the WestWood");
   SetLong("Giant deciduous trees crowd around a gentle ramp, "
           "aiding in the ramp's support.  The ramp leads to a wooden "
           "platform up in the air to the north.  A simple dirt path "
           "proceeds under that platform, heading to the south as "
           "well.");
   SetItems( ([
                ({ "simple dirt path","dirt path","simple path","path" }) :
                   "The path straggles under the platform, rambling "
                   "off to the north, but maintaining a fairly straight "
                   "line.  It avoids obstacles instead of ploughing "
                   "through or destroying them.  It goes off to the "
                   "south as well.",
                ({ "solid wooden platform","platform","wooden platform",
                   "solid platform" }) :
                   "The platform is held in middle of the sky by some "
                   "trees turned into supports.  The wooden ramp provides "
                   "access to the platform, which appears to be "
                   "frequently in use.",
                ({ "westwood","wood","woods","forest" }) :
                   (: GetLong :),
                ({ "giant deciduous trees","giant deciduous tree",
                   "giant trees","giant tree","deciduous trees",
                   "deciduous tree","tree","trees","deciduous" }) :
                   "Huge trees surround the platform and ramp, "
                   "some chopped in half so they can line up under "
                   "those items.",
                ({ "gentle ramp","wooden ramp","ramp" }) :
                   "It looks as if the ramp is made of the upper half "
                   "of those trees that were chopped into supports.  "
                   "It heads up to the solid wooden platform that "
                   "is suspended in mid-air to the north.",
           ]) );
   SetListen( ([
                 "default" : "Forest sounds echo through the trees.",
            ]) );
   SetSmell( ([
                "default" : "Sappy odors come from the forest.",
           ]) );
   SetExits( ([
                "north"     : M_ROOM + "ground_e",
                "up"        : M_ROOM + "ramp",
           ]) );
   AddExit("south",OUT,(: PreExit :));
   SetInventory( ([
                    M_NPC + "trav_wor" : 3+random(4),
               ]) );
}

int PreExit() {
   if(this_player()->GetProperty("monasterynoleave")) return 0;
   if(MAYLEAVE) return 1;
   return 0;
}
