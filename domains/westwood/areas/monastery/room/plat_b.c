#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("before a temple");
   
   SetLong("On the north side of this platform is a large building that "
           "appears to be a temple.  Two beautiful "
           "doors are on this side, leading in.  Rope bridges head off to "
           "the west, east, and south, supported by the long tree "
           "branches around them.  A wooden fence goes around the edge "
           "of the platform, with openings for the bridges.");
   SetItems( ([
                ({ "wooden fence","fence" }) :
                   "The fence is made of solid wood, and has been "
                   "carefully constructed to prevent people from falling "
                   "off the platform.",
                ({ "wooden platform","platform" }) :
                   (: GetLong :),
                ({ "temple" }) :
                   "The temple is a simple building with little "
                   "in the way of distinguishing marks, but two doors "
                   "lead inside from this end.",
                ({ "eclat temple","large building","building" }) :
                   "The temple is a simple building with little "
                   "in the way of distinguishing marks, but two doors "
                   "lead inside from this end.",
                ({ "rope bridges","rope bridge","bridges","bridge",
                   "ropes","rope","wood" }) :
                   "The rope bridges are simple, having wood on the "
                   "bottom to make it easy to walk across and ropes to "
                   "make the sides and to bind it all together.  They "
                   "go to the west, east, and south, and are help up "
                   "by the branches of trees.",
                ({ "long tree branches","long tree branch","long branch",
                   "long branches","tree branch","tree branches",
                   "branch","branches" }) :
                   "Branches fill the area around the platform, holding "
                   "it up and supporting the rope bridges.  They are "
                   "long and sturdy, splitting off into smaller ones "
                   "as they go along.",
           ]) );
   SetListen( ([
                 "default" : "Laughter twinkles in the air.",
            ]) );
   SetSmell( ([
                "default" : "Sweet pine smells come from inside the "
                   "building.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "plat_c",
                "south" : M_ROOM + "plat_e",
                "west"  : M_ROOM + "plat_a",
           ]) );
   SetEnters( ([
                 "temple" : M_ROOM + "temple",
            ]) );
   SetDoor("temple",M_ROOM + "templedoors");
   SetInventory( ([
                    M_NPC + "trav_wor" : 2,
                    M_NPC + "monk_j" : 1,
                    M_NPC + "monk_c" : 3,
               ]) );
}
