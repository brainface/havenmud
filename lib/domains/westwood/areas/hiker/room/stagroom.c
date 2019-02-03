#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetClimate("indoors");
   
   SetAmbientLight(25);
   SetShort("inside the West Wood");
   SetLong("The trees of the West Wood tower above, creating a "
           "canopy with their huge branches.  The trees create walls "
           "in all directions save down, where the dirt is dry and "
           "dusty.  A tunnel formed by bushes leads out to the east.");
   SetItems( ([
                ({ "bush tunnel","tunnel","hole","bushes","bush" }) :
                   "The tunnel to the east leads out of this strange "
                   "nook in the West Wood.  It is formed under some "
                   "bushes.",
                ({ "dry dusty dirt","dirt","dust" }) :
                   "The dirt is solid and firm, but the top layer is "
                   "dust.",
                ({ "west wood","wood","woods","room","strange nook",
                   "nook" }) :
                   (: GetLong :),
                ({ "huge branches","branches","branch",
                   "roof","canopy" }) :
                   "The sky above is blocked from sight and rain probably "
                   "could barely make it through the canopy formed above "
                   "by the branches.",
                ({ "huge trees","trees","tree","walls",
                   "wall" }) :
                   "The trees are giant, yet they are deciduous trees.  "
                   "Their branches lock above into a roof, and all around "
                   "clasp themselves close to each other to wall in this "
                   "'room'.",
           ]) );
   SetItemAdjectives( ([
                         "dirt" : ({ "dry","dusty" }),
                         "branches" : ({ "huge" }),
                         "trees" : ({ "huge" }),
                    ]) );
   SetExits( ([
                "out" : H_ROOM + "meadow_1",
           ]) );
   SetInventory( ([
                    H_NPC + "wstag" : 1,
               ]) );
}
