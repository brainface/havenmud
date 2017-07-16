#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("inside a tree house");
   SetDomain("WestWood");
   SetLong("The tree house is small, as there is not much room for "
           "such thing on the branch, but it is plenty large for "
           "children.  While it is inside, there are so many holes in the "
           "construction between the branches used, it is as if it is "
           "outside.  An opening in the walls leads out.");
   SetItems( ([
                ({ "tree house","house","treehouse","hut" }) :
                   (: GetLong :),
                ({ "supporting branch","branch","floor" }) :
                   "The floor of the tree house is the "
                   "branch that supports it; it is brown and plain and "
                   "has little spare room beyond what has been used "
                   "for building.",
                ({ "holes between branches","holes","hole",
                   "hole between branches" }) :
                   "Children are not very picky about how things they "
                   "make are built, and as such, there are many holes "
                   "between the branches that let in light and fresh "
                   "air, making it almost the same as being outside.",
                ({ "wall branches","wall branch","walls","wall","branches",
                   "branch","opening" }) :
                   "The walls of the tree house are full of holes, "
                   "but one seems purposeful:  One opening in the walls "
                   "is large enough to let people out.  Many branches "
                   "had been used to make the tree house.",
           ]) );
   SetExits( ([
                "out" : M_ROOM + "branch",
           ]) );
   SetInventory( ([
                    M_NPC + "kid" : 3+random(4),
               ]) );
}