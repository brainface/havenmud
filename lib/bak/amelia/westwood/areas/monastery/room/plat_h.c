#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   SetDomain("WestWood");
   SetLong("The world bends slightly in the breeze here, swaying to and "
           "fro on the long branches that hold everything up.  The trunks "
           "of the trees are thinner in this area, and the platform "
           "is attached to the branches more than the trunks.  A ladder "
           "heads down off the edge of this platform, and ramps extend "
           "to the west and south, reaching other platforms in their "
           "meandering path.");
   SetItems( ([
                ({ "wooden ladder","wood ladder","ladder","wood" }) :
                   "The ladder leads down out of the clouds and into the "
                   "world where the trees are thicker and the platforms "
                   "more stable.  It is wooden and looks like it has been "
                   "used often.",
                ({ "meandering ramps","meandering ramp","ramps","ramp",
                   "wooden ramps","wooden ramp","wood ramps","wood ramp",
                   "meandering path","path","wood" }) :
                   "The ramps go to the west and south in raggedly formed "
                   "directions.  They head to all the nearby branches "
                   "that are distinctly larger than the rest, ignoring "
                   "the straight path to the other platforms.  They dip "
                   "up and down and curve to the left and right, but "
                   "for the most part, they continue in the same "
                   "direction.",
                ({ "wooden platforms","wooden platform","platforms",
                   "platform","wood platform","wood platforms",
                   "wood" }) :
                   "The platforms are made of wood, and hang on the "
                   "long branches that come off the shrinking trees.  "
                   "Two ramps are attached to this platform, and they "
                   "go west and south.  The platforms in those directions "
                   "are difficult to see from here; other branches "
                   "obscure the view.",
                ({ "shrinking trees","shrinking tree","trees","tree",
                   "wood" }) :
                   "The trees shrink in size as they climb to the "
                   "beautiful sky.  The trunks are thinner and the "
                   "branches skinnier, and everything in general is "
                   "younger and more alive, dancing in the wind in some "
                   "places.  Luckily, the platforms and ramps are not "
                   "attached there.",
                ({ "world","area" }) :
                   (: GetLong :),
                ({ "long branches","long branch","branches","branch",
                   "wood" }) :
                   "Supporting the platform and ramps are the branches, "
                   "all of them long and counting up to many.  They are "
                   "not as thick as those below nor attached to as thick "
                   "of trunks; it is probably a less safe area in this "
                   "neck of the woods.",
                ({ "thinner trunks","thin trunks","thinner trunk",
                   "thin trunk","trunks","trunk","wood","thinning trunks",
                   "thinning trunk" }) :
                   "The trunks work thier way to a smaller and smaller "
                   "diameter as they grow into the sky.  Many branches "
                   "cling to the trunks, and these are what the platform "
                   "and ramps are attached to as opposed to the thinning "
                   "trunks.",
           ]) );
   SetListen( ([
                 "default" : "Aside from some giggling below, silence "
                    "glides on the air.",
            ]) );
   SetSmell( ([
                "default" : "The air is clean and sweet at this altitude.",
           ]) );
   SetExits( ([
                "south" : M_ROOM + "plat_i",
                "west"  : M_ROOM + "plat_g",
                "down"  : M_ROOM + "plat_d",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_c" : 1,
                    M_NPC + "monk_h" : 2,
               ]) );
}