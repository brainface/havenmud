#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a branch");
   
   SetLong("Up against the tree trunk, a group of sticks has been "
           "arranged into a hut-like building that appears ready to "
           "topple over.  The branch itself is sturdy and strong, "
           "ready to hold up the entire world if necessary.  "
           "It goes off to the southeast and entangles itself with the "
           "branches of other trees.  The trunk looks like it would be " 
           "easy to climb down to the platform on.");
   SetItems( ([
                ({ "hut-like building","building","hut","sticks","stick",
                   "group of sticks","group","treehouse","house",
                   "tree house","fallen brnaches","fallen branch",
                   "branch","branches" }) :
                   "The hut is made of fallen branches that were "
                   "connected and nailed together into a sort of "
                   "treehouse.  It has an opening to one side of it, "
                   "but it isn't very well constructed.  It will probably "
                   "stay together a while longer, at any rate.",
                ({ "sturdy branch","branch" }) :
                   "The branch is very large, and is attached quite firmly "
                   "to the tree trunk.  It continues to the southeast, "
                   "where it wraps itself up in a bunch of other "
                   "branches, and splits into a few itself.",
                ({ "other branches","branches","branch" }) :
                   "There are many branches coming off this tree trunk, "
                   "and others to the southeast that tangle up with this "
                   "branch.",
                ({ "wooden platform","platform" }) :
                   "Around the tree is a wooden platform, but it is "
                   "barely visible from here.  The trunk blocks most of "
                   "it, the branches almost all the rest.  It is possible "
                   "to climb down the trunk and get to it.",
           ]) );
   SetListen( ([
                 "default" : "Laughter echos through the forest.",
            ]) );
   SetExits( ([
                "southeast" : M_ROOM + "branch2",
           ]) );
   SetEnters( ([
                 "treehouse" : M_ROOM + "treehouse",
            ]) );
   SetInventory( ([
                    M_ROOM + "tree_cd" : 1,
                    M_NPC + "kid" : random(3)+2,
               ]) );
}
