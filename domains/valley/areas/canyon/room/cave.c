#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a cave");
   SetDomain("Valley");
   SetDomain("Valley");
   SetLong("The opening to the north lets in light and lots of "
           "sound, illuminating the cave quite nicely.  Trees "
           "cover much of the exit, concealing its view from "
           "outside.  A pile of wood fills the center of the room, "
           "some of it charred and some fresh and new.  Marks on "
           "the ceiling show that the firewood was, at one time, "
           "flaming.");
   SetItems( ([
                ({ "illuminated cave","cave" }) :
                   (: GetLong :),
                ({ "concealing trees","concealing tree","trees","tree",
                   "opening","exit" }) :
                   "The trees go over a lot of the opening to the "
                   "north, hiding it from those outside.  It is "
                   "very visible in here, though.",
                ({ "pile of wood","firewood","pile","wood","heap" }) :
                   "The wood is piled in a heap in the center of the "
                   "cave, some of it looking as if its been burning.  "
                   "Smoke marks on the ceiling show that it has been.  "
                   "Much of the wood currently there is fresh and new.",
                ({ "smoke marks","smoke mark","marks","mark","ceiling" }) :
                   "The smoke marks on the ceiling are black and "
                   "sooty, much like smoke itself.",
           ]) );
   SetObviousExits("north");
   SetExits( ([
                "north" : JD_ROOM + "/valley_8",
           ]) );
   SetInventory( ([
                    JD_NPC + "/child" : 3+random(4),
               ]) );
}
