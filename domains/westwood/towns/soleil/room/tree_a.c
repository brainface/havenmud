// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetShort("a wooden platform");
   
   SetLong("Suspended in the trees by a few supports, but mostly by the "
           "surrounding branches and trees, this wooden platfrom seems "
           "oblivious to the years.  A few nicks and scratches cover the "
           "surface, and lots of dirt and pine needles has been tracked "
           "across it, but it shows no weak rotting spots.  A ramp "
           "on the south side of the platform slopes down towards the "
		"ground, and a large "
           "building to the west is marked 'town hall' in many languages.  "
           "To the north, a rope bridge heads off.  There is a comfortable "
           "home that can be entered from here on the east side of the "
           "platform.");
   SetItems( ([
                ({ "hemlock trees","trees","hemlock tree","tree","branches",
                   "branch","supports","support" }) :
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
                   "platform and rope bridge, as well as the ramp "
                   "that heads down towards the ground.",
                ({ "down ramp","ramp" }) :
                   "The ramp to the south heads down towards the ground, "
                   "sprinkled with pine needles and dirt.  It is, "
                   "like all other permanent structures seem to be around "
                   "here, in extroadanarily good condition.",
                ({ "town hall","building","hall","townhall" }) :
                   "The large sign on the building proclaims in many "
                   "languages that this is Soleil's Town Hall.",
                ({ "sign" }) :
                   "The large sign on the building proclaims in many "
                   "languages that this is Soleil's Town Hall.",
                ({ "comfortable home","home","building" }) :
                   "The comfortable home looks like it could be entered "
                   "from this side.  It is frequently entered, and most "
                   "likely anyone is quite welcome there.",
                ({ "rope bridge","bridge","rope" }) :
                   "The rope bridge, much like the platform, is "
                   "almost completely bereft of that normal wear-and-"
                   "tear associated with things constantly left out "
                   "doors and in the weather.  Similiar as well, it "
                   "seems to have been used frequently by the dirt "
                   "and pine needles.",
           ]) );
   SetItemAdjectives( ([
                         "town hall" : ({ "town","large" }),
                         "home" : ({ "comfortable","clean" }),
                    ]) );
   SetExits( ([
                "down" : S_ROOM + "gate",
                "north" : S_ROOM + "tree_b",
           ]) );
   SetEnters( ([
                 "hall" : S_ROOM + "townhall",
                 "home" : S_ROOM + "mercha",
            ]) );
   SetInventory( ([
                    S_NPC + "citizenm" : random(2),
                    S_NPC + "citizenf" : random(2)+1,
                    S_NPC + "guard_gate" : random(3),
               ]) );
}
