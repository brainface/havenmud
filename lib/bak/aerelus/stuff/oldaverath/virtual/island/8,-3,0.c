
// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("at the edge of a well-lit forest");
   SetLong("Devil's clubs flourish in large patches, their prickly "
              "stalks discouraging touch.  Scattered around this area, "
              "silver birches stretch high to the sky, joined by oak "
              "trees and white mulberry trees.  A few wild roses grow "
              "near the north side, blooming a pale pink.  Joining the "
              "trees in a quest for the sky is a tall stone tower.");
   SetItems( ([
                ({ "tall stone tower","tower", }) :
                   "Formed of large blocks of stone, the tower has an impressive aura.",
                ({ "well-lit forest","forest" }) : (: GetLong:),
                ({ "devil's clubs","clubs","club","devil's club" }) :
                   "The devil's clubs grow in clumps, with prickly tan "
                   "stalks rising out of the ground like miniature "
                   "trees, terminating in a canopy of green leaves with "
                   "clusters of red berries.",
                ({ "prickly tan stalks","stalks","stalk","thorns","thorn" }) :
                   "Thorns coat the stalks of the devil's clubs, as well as "
                   "the veins of their green leaves.",
                ({ "green leaves","leaves","leaf" }) :
                   "Green leaves sprout off most of the plants in the area, "
                   "including the devil's club, roses, and birches.  The roses "
                   "have small, oval leaves, while the devil's clubs posses "
                   "large maple-leaf like leaves with thorns on their veins.",
                ({ "silver birches","birches","trees","birch","tree" }) :
                   "With branches blocking out much of the sky, the silver birches "
                   "cluster near the tower.",
                ({ "white mulberries","mulberries","mulberry","trees","tree" }) :
                   "Shorter than the other trees but with no less branches, the "
                   "white mulberries flourish.",
                ({ "oak trees","oak","trees","oaks","tree" }) :
                   "The oak trees stretch high into the sky, mixed with birches and "
                   "mulberries.",
                ({ "branches","branch" }) :
                   "All the trees in this area possess branches.",
                ({ "wild roses","roses","rose" }) :
                   "The wild roses have pale buds on the verge blooming.",
           ]) );
   SetItemAdjectives( ([
                         "stalks" : ({ "prickly","tan" }),
                         "leaves" : ({ "green" }),
                         "birches" : ({ "silver","birch" }),
                         "mulberry" : ({ "white","mulberry" }),
                         "oak" : ({ "oak" }),
                         "roses" : ({ "wild","pale","pink" }),
                    ]) );
   SetListen( ([
                 "default" : "Branches clack against each other in the wind.",
            ]) );
   SetSmell( ([
                "default" : "A slight rose scent fills the air.",
                "roses" : "The roses have a mild perfumed aroma.",
           ]) );
   SetEnters( ([
                 "tower" : FOREST_ROOMS + "tower0",
            ]) );
   SetExits( ([
                "west" : AVERATH_ISLAND + "7,-3,0",
                "east" : AVERATH_ISLAND + "9,-3,0",
                "south" : AVERATH_ISLAND + "8,-4,0",
                "north" : AVERATH_ISLAND + "8,-2,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "baldeagle" : 2,
               ]) );
}
