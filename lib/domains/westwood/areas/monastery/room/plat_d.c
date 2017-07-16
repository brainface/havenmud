#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   
   SetLong("The wooden platform is circular in shape, and connected to "
           "it are many rope bridges that lead to other platforms.  "
           "A ladder is run up against the building planted against the "
           "edge of the platform; the ladder goes up to another platform "
           "that is above.  Trees hold up the entire structure.");
   SetItems( ([
                ({ "deciduous trees","trees","tree","deciduous tree",
                   "deciduous","wood" }) :
                   "The trees are the most crucial aspect of the "
                   "area; nothing could be held in the air without "
                   "their help.  Long branches spread out under the "
                   "platform and hold it in place, other ones clutch "
                   "onto the rope bridges or hold the ladder in place.  "
                   "Thick trunks support the platform and rise into "
                   "the air, the branches splitting out from it on "
                   "occasion.  Leaves cover the trees as well, some "
                   "of them blowing around in the air.",
                ({ "long branches","tree branches","branches","branch",
                   "tree branch","long branch","wood" }) :
                   "The branches are thick and rough, heading out of "
                   "the tree trunks at awkward angles.  Somehow, they "
                   "are all directed to usefull areas, or at least "
                   "non-obstructive spots.",
                ({ "blowing leaves","leaves","leaf","blowing leaf" }) :
                   "The leaves are gentle and green, dancing around "
                   "the air on the breeze and clinging wildly to the "
                   "branches.",
                ({ "small classroom","classroom","building" }) :
                   "The building is labeled as a classroom, but it can't " 
                   "be a very large one.  An open entrance leads inside "
                   "it.",
                ({ "wooden ladder","wood","ladder" }) :
                   "The trees, building, and platforms are all attached "
                   "to the wooden ladder that leads up into higher "
                   "areas.  The ladder looks very sturdy, even though "
                   "it climbs in a very verticle manner.",
                ({ "wooden platforms","wooden platform",
                   "platform","platforms","solid wood","wood" }) :
                   "The platform is made of solid wood, "
                   "and could hold up a lot more weight than it already "
                   "is.  It is circular, and rope bridges connect to "
                   "it leading off to the east and north.  A building "
                   "sits on the platform on the west edge.",
                ({ "rope bridges","rope","bridge","bridges",
                   "rope bridge","wood" }) :
                   "The rope bridges head to the east and north, " 
                   "attached carefully to the platform and to "
                   "nearby trees.  Boards fill out the bottom of "
                   "the rope bridges so less agile people can still "
                   "make it across.",
                ({ "wooden boards","wooden board","boards","board",
                   "wood" }) :
                   "The boards make it possible to walk across the "
                   "the rope bridges with an almost zero percent chance "
                   "on falling.  The extremely talented person could "
                   "probably manage, but few others.",
           ]) );
   SetListen( ([
                 "default" : "The trees shake noisily.",
            ]) );
   SetSmell( ([
                "default" : "Simple forest smells waft fill the air.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "plat_e",
                "north" : M_ROOM + "plat_a",
                "up"    : M_ROOM + "plat_h",
           ]) );
   SetEnters( ([
                 "classroom" : M_ROOM + "class",
            ]) );
   SetInventory( ([
                    M_NPC + "trav_wor" : 2,
                    M_NPC + "student" : random(3),
                    M_NPC + "monk_h" : 1,
                    M_NPC + "monk_c" : random(4),
               ]) );
}
