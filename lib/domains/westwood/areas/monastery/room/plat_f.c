#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   
   SetLong("Rope bridges string themselves out to the north and west, "
           "attached to many thick branches and tree trunks.  The "
           "platform itself is supported mainly by the trunks of the "
           "trees, as opposed to the branches, but both seem to be "
           "equally well supported and sufficient in holding up weight.  "
           "More platforms exist to the north and west, connected to "
           "this one by the rope bridges.");
   SetItems( ([
                ({ "thick branches","thick branch","branches","branch" }) :
                   "The branches are very thick here, coming out of "
                   "even thicker tree trunks.  They aid in the support "
                   "of all the various things that hold the world up "
                   "here.",
                ({ "thick tree trunks","thick tree trunk","trunks","trunk",
                   "thicker tree trunks","thicker tree trunk","tree trunk",
                   "tree trunks","thick trunks","thick trunk",
                   "thicker trunks","thicker trunk" }) :
                   "The trunks of the trees are quite thick here, making "
                   "it a simple task to hold up the platform and the "
                   "rope bridges.  One in particular looks larger "
                   "than the rest, and it might even be possible to climb "
                   "that tree.",
                ({ "rope bridges","rope bridge","rope","ropes","bridges",
                   "bridge" }) :
                   "The rope bridges span the distance between this "
                   "platform and the others to the north and west.  "
                   "They are attached in many spots to tree branches, "
                   "making it easy to walk across the bridges and "
                   "harder to fall.",
                ({ "wooden platforms","wooden platform","wood","platforms",
                   "platform","wood platform","wood platforms" }) :
                   "The platform here is large, basically a circle.  "
                   "It has two rope bridges attached to it, which lead "
                   "to two other platforms.  Those are hardly visible from "
                   "here.",
           ]) );
   SetListen( ([
                 "default" : "Laughter and joy fill the air.",
            ]) );
   SetExits( ([
                "north" : M_ROOM + "plat_c",
                "west"  : M_ROOM + "plat_e",
           ]) );
   SetInventory( ([
                    M_ROOM + "tree_cu" : 1,
               ]) );
   SetInventory( ([
                    M_NPC + "kid" : random(2),
                    M_NPC + "monk_j" : 1,
                    M_NPC + "monk_h" : 2,
                    M_NPC + "trav_wor" : 3,
               ]) );
}