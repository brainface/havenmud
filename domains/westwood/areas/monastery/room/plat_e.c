#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   
   SetLong("High above the ground is this wooden platform, so high "
           "that the dirt is hidden among the branches of the trees.  "
           "A ramp leads down towards the ground, slanted gently.  "
           "Rope bridges lead to other platforms to the north, east "
           "and south; they appear sturdy enough for anyone to walk on "
           "without falling to the ground.");
   SetItems( ([
                ({ "wooden platforms","wooden platform","platform",
                   "platforms","wood" }) :
                   "The platform here is probably around medium size; "
                   "it is a general crossroad for anyone who wishes "
                   "to travel through this area.  The others are "
                   "hard to view completely from here; however, the "
                   "one to the north appears to be the largest.",
                ({ "hidden ground","dirt","ground" }) :
                   "It cannot be seen through the branches.",
                ({ "deciduous trees","deciduous tree","tree","trees",
                   "wood" }) :
                   "Trunks, branches, and leaves form the deciduous "
                   "trees.  Some of the branches help support the "
                   "platforms and bridges, and the trunks are used for "
                   "support sometimes as well.  The leaves shake on the "
                   "branches and some flutter through the air, having "
                   "fallen off.",
                ({ "tree trunks","tree trunk","trunk","trunks","wood" }) :
                   "The trunks are the central part of the tree; all the "
                   "branches are attached it to.  They are thicker than "
                   "the branches, as well, and don't hold leaves.",
                ({ "tree branches","tree branch","branches","branch",
                   "limbs","limb","wood" }) :
                   "Trunks split apart and sprout branches all over, "
                   "those branches splitting into smaller ones and the "
                   "smaller ones splitting even more.  Leaves come out "
                   "towards the ends of the branches, fluttering in the "
                   "wind.  Many of the branches have been used to aid "
                   "in the support of the platforms and bridges, holding "
                   "them up with the larger limbs.",
                ({ "rustling leaves","rustling leaf","leaves","leaf" }) :
                   "The leaves flutter around through the air, and "
                   "rustle on the trees.  They grow off the ends of the "
                   "branches in clumps, grouping together and covering "
                   "the sky.",
                ({ "wooden ramp","ramp","wood" }) :
                   "The ramp slants towards the ground, heading off from "
                   "the southern end of the platform.",
                ({ "rope bridges","rope bridge","bridge","bridges",
                   "ropes","rope" }) :
                   "The bridges provide access between the platforms, "
                   "and despite the general belief on how all rope "
                   "bridges are completely unsafe, these appear to be "
                   "strong and relatively secure.",
           ]) );
   SetListen( ([
                 "default" : "Laughter fills the air.",
            ]) );
   SetSmell( ([
                "default" : "The smells of the forest surround the " 
                   "area.",
           ]) );
   SetExits( ([
                "north" : M_ROOM + "plat_b",
                "east"  : M_ROOM + "plat_f",
                "west"  : M_ROOM + "plat_d",
                "down"  : M_ROOM + "ramp",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_c" : 3,
                    M_NPC + "monk_h" : 2,
                    M_NPC + "trav_wor" : 4,
               ]) );
}