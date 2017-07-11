#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"
 
static void create() {
   room::create();
   SetTown("Soleil");
   SetShort("path to the Eclatish Temple");
   
   SetLong("The trees Soleil is built upon grow larger as they get closer "
           "to the Eclatish Temple, and the type changes from large "
           "hemlocks into giant spruce trees.  The platform is made of "
           "rough, worn wood, older than the planks found at the other side "
           "of the village.  A short staircase heads up towards a small "
           "hut.  A rope bridge heads to a platform in the northwest "
           "and the church can be entered to the east.  Spruce needles "
           "cover the platform.  Another building is just to the "
           "north.");
   SetItems( ([
                ({ "giant spruce trees","giant trees","spruce trees",
                   "trees","giant spruce tree","giant tree",
                   "spruce tree","tree" }) :
                   "The spruce trees tower up above the hemlocks, "
                   "swaying gently above the Eclatish Temple and hiding it "
                   "from view..",
                ({ "art gallery","gallery","building" }) :
                   "The other building is an art gallery.  "
                   "It can be entered from this side.  It appears "
                   "to be well-lit inside, and it seems to be set "
                   "up to allow someone to do lecturing or training "
                   "inside.",
                ({ "eclatish temple","temple" }) :
                   "The Eclatish Temple is to the east, half-hidden by "
                   "trees.",
                ({ "short staircase","staircase" }) :
                   "The stairs lead up to the hut.",
                ({ "small hut","hut" }) :
                   "A short staircase leads up to the hut, which can "
                   "probably be entered from the staircase's top.  "
                   "The hut seems to have a generally cheery atmosphere "
                   "to it.",
                ({ "hemlock trees","trees","hemlock tree","tree","branches",
                   "branch","supports","support" }) :
                   "The hemlock trees and branches almost surround this "
                   "platform, providing it support and allowing it to "
                   "disobey the call of gravity which suggests that it "
                   "touch the dirt ground instead of hang in the trees.  "
                   "More spruce trees surround this platform than "
                   "others in Soleil.",
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
                   "The rope bridge, much like the platform, is "
                   "almost completely bereft of that normal wear-and-"
                   "tear associated with things constantly left out "
                   "doors and in the weather.  Similiar as well, it "
                   "seems to have been used frequently by the dirt "
                   "and pine needles.  It heads off to the northwest.",
           ]) );
   SetExits( ([
                "northwest" : S_ROOM + "tree_b",
                "east" : S_ROOM + "temple",
                "up" : S_ROOM + "bakery", 
          ]) );
   SetEnters( ([
                 "gallery" : S_ROOM + "gallery",
             ]) );
   SetInventory( ([
                    S_NPC + "citizenm" : random(2),
                    S_NPC + "citizenf" : random(2),
                    S_NPC + "druid_acclima" : 1,
               ]) );
}
