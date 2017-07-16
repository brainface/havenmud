#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(5);
   SetShort("hallway end");
   SetLong("The hall ends here in the dark midst of cobwebs and scurrying "
           "marks on the dust of the floor.  To the west is an opening "
           "that is much smaller than its pair to the east, but still "
           "remains large enough to allow access.  The hallway continues "
           "to the south.");
   SetItems( ([
                ({ "hall openings","opening","openings","hall opening" }) :
                   "The openings are matched up, one on each side of "
                   "the hall, but the one to the east is significantly "
                   "larger than the one to the west.",
                ({ "hallway end","hallway","end","hall" }) :
                   (: GetLong :),
                ({ "shabby cobwebs","shabby cobweb","cobweb","cobwebs",
                   "web","webs" }) :
                   "The cobwebs have collecting a good bit of dust and "
                   "many rips and tears, rendering them useless to their "
                   "builder.",
                ({ "dust particles","dust","particles","particle", 
                   "dust particle" }) :
                   "The dust clings to the cobwebs and covers the floor.",
                ({ "scurrying marks","scurrying mark","floor","marks",
                   "mark" }) :
                   "The marks look as if they were made by some "
                   "rodent rushing apart in the dark and dust.",
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/c_side6",
                "south" : VC_ROOM + "/c_hall2",
                "west"  : VC_ROOM + "/c_side5",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
