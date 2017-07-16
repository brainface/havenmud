#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the walls");
   SetLong("This is a small nook inside the castle walls, leading into "
           "a tower that is to the north.  Solid stones of rather large "
           "sizes make up much of the wall, with smaller rocks fitting "
           "in between them to make up for possible gaps.  A door "
           "leads into the square tower, while to the west the world "
           "opens up.  A couple torches line the wall.");
   SetItems( ([
                ({ "small nook","nook","castle" }) :
                   (: GetLong :),
                ({ "castle walls","castle wall","wall","walls",
                   "solid stones","solid stone","stone","stones",
                   "smaller rocks","smaller rock","rock","rocks",
                   "small rock","small rocks","square tower","tower",
                   "torch","torch" }) :
                   "The torches flame dully up against the walls, "
                   "which are made up of the solid stones and small "
                   "rocks of a gray color.  The tower to the north "
                   "is a blocky, square shape, and a door leads into "
                   "it from here.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/tower_1a",
                "west" :  VC_ROOM + "/gen_04",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
