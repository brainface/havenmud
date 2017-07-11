#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

int butterfly_trees;
void butterfly_tree();

static void create() {
   room::create();
   SetDomain("Valley");
   butterfly_trees = 0;
   SetShort("inside a canyon");
   SetLong("The canyon branches off in three directions here, one "
           "to the east, another to the south, and the final over "
           "to the northwest.  Trees grow thickly to the southwest, "
           "but are more thinned out here.  To the northwest, there "
           "appear to be hardly any at all.");
   SetItems( ([
                ({ "canyon branching","canyon","cliff" }) :
                   (: GetLong :),
                ({ "deciduous trees","deciduous tree","trees",
                   "tree" }) :
                   (: butterfly_tree :),
           ]) );
   SetObviousExits("east, south, northwest");
   SetExits( ([
                "east"      : JD_ROOM + "/canyon_4",
                "south"     : JD_ROOM + "/canyon_2",
                "northwest" : JD_ROOM + "/cliff_other_bottom",
           ]) );
   SetInventory( ([
                    JD_NPC + "/beetle_dung" : 4,
                    JD_NPC + "/snake_green" : 1,
                    JD_NPC + "/centipede" : 2,
               ]) );
}

void butterfly_tree() {
   if(butterfly_trees) {
      message("other action","The trees are very prosperous, and grow "
              "thick to the south.  The seem to be a bit thinner here "
              "however, and to the east and northwest there are "
              "even less.  The trees seem somehow empty, even though "
              "the flourish.",environment(this_player()));
      return;
   }
   butterfly_trees = 1;
   message("other action","A cloud of butterflies takes off from the trees and "
          "flees north in a surprisingly dance of beauty.  They "
          "seemed to have sensed someone looking at their hiding "
          "place, and are now gone beyond the cliff.",this_player());;
   return;
}
