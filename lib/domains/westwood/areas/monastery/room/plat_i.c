#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   
   SetLong("Wrinkled leaves mix with fresh green leaves are they run "
           "through the air and collect at nooks in branches and "
           "tree trunks.  The rest of the world merely sways in the "
           "breeze up in here; the platform wiggles with the branches "
           "that keep it in the air, and the tree trunks themselves "
           "move some in the wind.  A ramp dances through the strongest "
           "of the branches, trying to find the sturdiest route to "
           "the north.");
   SetItems( ([
                ({ "wooden ramp","ramp","wood ramp" }) :
                   "The ramp goes all over and curves around and moves "
                   "up and down as it goes to the north.  It tries to "
                   "attach to the largest of the branches, the ones that "
                   "will do the best at holding it up.  As such, it "
                   "doesn't follow a straight course by winds all over.",
                ({ "tree trunks","tree trunk","trunks","trunk" }) :
                   "The trunks do little of the work on supporting the "
                   "platform and ramp, but they are in charge of all the "
                   "branches that are doing that work.  They are thinner "
                   "than those below, but seem to be doing fine, even "
                   "though they sway from side to side at times.",
                ({ "world" }) : (: GetLong :),
                ({ "tree branches","tree branch","branches","branch" }) :
                   "The branches are the main supporters of the platform "
                   "and its ramp, sliding under them and holding on "
                   "so that they stay in the world up here.  Twisting "
                   "together and intertwining, the branches also collect "
                   "leaves in little nooks.",
                ({ "nooks for leaves","nook in branch","nooks",
                   "nook","nooks in tree trunks","nooks in trunks",
                   "nook in trunk","nook in tree trunk","nooks in branches",
                   "nook for leaves","little nooks","little nook" }) :
                   "The branches curl together and the trunks have little "
                   "dents, all of which are collecting leaves.  They "
                   "are turned away from the current wind, and protect "
                   "the leaves from running away in it.",
                ({ "wooden platform","platform" }) :
                   "The wooden platform is as solid placed as it "
                   "can be in the air here, but the branches that support "
                   "it are thinner than those below, as well as the "
                   "tree trunks; it still moves some with the wind.",
                ({ "wrinkled leaves","wrinkled leaf","leaves","leaf" }) :
                   "Some of the leaves that dance about are brown and "
                   "winkled, having fallen and died since them.",
                ({ "fresh green leaves","fresh green leaf","green leaves",
                   "green leaf","fresh leaves","fresh leaf","leaves",
                   "leaf" }) :
                   "The leaves that have fallen the most recently are "
                   "still alive and green, surprised by their sudden "
                   "detachment from their branches.",
           ]) );
   SetListen( ([
                 "default" : "Creaking branches and tree trunks sway "
                    "in the wind, and leaves noisily clatter about.",
            ]) );
   SetSmell( ([
                "default" : "The world smells fresh and alive.",
           ]) );
   SetExits( ([
                "north" : M_ROOM + "plat_h",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_j" : 2,
                    M_NPC + "monk_h" : 1,
               ]) );
}