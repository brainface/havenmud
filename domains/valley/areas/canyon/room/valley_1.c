#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside the valley");
   SetDomain("Valley");
   SetLong("The cliff walls rise sharply to the west and south, "
           "blocking exits it those directions.  To the north, east, and "
           "southeast, the trees part to allow movement.  A breeze "
           "causes the leaves to shudder on the trees and attempt "
           "to fall to the dirt ground.");
   SetItems( ([
                ({ "inside the valley","valley","cliff","cliff walls",
                   "cliff wall","wall","walls" }) :
                   (: GetLong :),
                ({ "decidious trees","decidious tree","tree","trees",
                   "leaf","leaves" }) :
                   "The leaves shake to and fro on the decidious "
                   "trees, some fluttering down to the ground.  "
                   "The trees allow passage to the north, east, and "
                   "southeast.",
                ({ "dirt ground","ground","dirt","soil","perfect soil",
                   "rich dirt" }) :
                   "The dirt is loose and slightly moist, creating "
                   "the perfect soil for plants to grow in.  Forest "
                   "debris decays on top of the rich dirt, fallen "
                   "from the plants and animals of the area.",
                ({ "forest debris","debris","bits","pieces",
                   "bit","piece" }) :
                   "Bits and pieces of plants have fallen from their "
                   "stalks and began work at decomposing into rich "
                   "soil.",
                ({ "forest plants","forest plant","plant","plants" }) :
                   "The plants are of various different types, "
                   "but most have very similar charectoristics:  "
                   "They are green with bits of brown and are growing "
                   "with great health.",
           ]) );
   SetObviousExits("north, east, southeast");
   SetExits( ([
                "southeast" : JD_ROOM + "/cliff_bottom",
                "east"      : JD_ROOM + "/valley_2",
                "north"     : JD_ROOM + "/valley_4",
           ]) );
   SetInventory( ([
                    JD_NPC + "/snake_green" : 2,
                    JD_NPC + "/butterfly" : 3,
               ]) );
}
