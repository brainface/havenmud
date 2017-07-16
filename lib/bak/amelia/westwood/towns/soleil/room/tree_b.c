#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetShort("a wooden platform");
   SetDomain("WestWood");
   SetLong("Suspended in the trees by a few supports, but mostly by the "
           "surrounding branches and trees, this wooden platfrom seems "
           "oblivious to the years.  A few nicks and scratches cover the "
           "surface, and lots of dirt and pine needles has been tracked "
           "across it, but it shows no weak rotting spots.  "
           "A worn ladder goes down from this platform, and rope "
           "bridges head off to the north and south.  "
           "A new ladder leads up higher into the trees.");
   SetItems( ([
               ({ "new ladder","ladder" }) :
                  "The new ladder leads up into "
                  "trees into the new area "
                  "of Soleil.",
                ({ "worn ladder","ladder" }) :
                   "The ladder is strong, but it speaks of age.  It "
                   "doesn't have the same timeless look as some of the "
                   "other structures in Soleil did.  It seems to be "
                   "getting old.  It leads down.",
                ({ "hemlock trees","trees","hemlock tree","tree",
                   "branches","branch","supports","support" }) :
                   "The hemlock trees and branches that surround this "
                   "platform provide its support, allowing it to "
                   "disobey the call of gravity which suggests that it "
                   "touch the dirt ground instead of hang in the trees.",
                ({ "suspended wooden platform","platform","wooden platform",
                   "suspended platform","surface" }) :
                   "Very sturdy and very strong, the platform uses the "
                   "nearby branches and trunks to stay up here in the "
                   "air.  It seems to be in unusually good condition.",
                ({ "nicks and scratches","nicks","scratches","nick",
                   "scratch" }) :
                   "The nicks and scratches are scarce across this "
                   "wooden platform.  Normal rules about getting worn "
                   "out obviously don't apply to wood here.",
                ({ "platform supports","supports","support","platform "
                   "support" }) :
                   "The supports consist of trees whose upper half has "
                   "been cut off, right at the point where the platform "
                   "is to lie.  The upper half probably became the boards "
                   "for the platform or some other structure here in "
                   "Soleil.",
                ({ "dirt and pine needles","dirt","pine needles","needles",
                   "pine needles","needle" }) :
                   "Dirt and pine needles are scattered across the "
                   "platform and rope bridge.",
                ({ "rope bridge","bridge","rope" }) :
                   "The rope bridges, much like the platform, are "
                   "almost completely bereft of that normal wear-and-"
                   "tear associated with things constantly left out "
                   "doors and in the weather.  Similiar as well, they "
                   "seems to have been used frequently by the dirt "
                   "and pine needles.  They head off to the north "
                   "and south.",
           ]) );
   SetExits( ([
                "south" : S_ROOM + "tree_a",
                "north" : S_ROOM + "tree_c",
                "up" : S_ROOM + "up1",
                "down" : S_ROOM + "pool",
           ]) );
   SetInventory( ([
                    S_NPC + "citizenm" : random(2)+1,
                    S_NPC + "citizenf" : random(2),
                    S_NPC + "baker_tia" : 1,
               ]) );
}
