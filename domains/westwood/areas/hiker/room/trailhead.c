#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"
#define WORLD "/domains/westwood/virtual/soleilroad/0,20"

int PreExit();

static void create() {
   room::create();
   
   SetShort("start of a trail");
   SetLong("A narrow trail starts here, heading with a gentle slope to "
           "the northwest.  Planks of wood, each about a foot across and "
           "twelve feet long, run on top of the path with the obvious "
           "intention of being walked upon.  The ground underneath is "
           "solid, however, and appears to be walked in frequently "
           "despite the boards.  A larger path heads off to the southeast.");
   SetItems( ([
                ({ "trail start","start of a trail","start of trail",
                   "start","trail","narrow trail","path" }) :
                   (: GetLong :),
                ({ "solid ground","ground","gentle slope","slope" }) :
                   "The ground beneath the planks is solid, dry, and "
                   "very firm.  It slopes gently upward, heading to "
                   "the northwest.",
                ({ "planks of wood","planks","plank","wood",
                   "wooden planks","wooden plank","boards","board" }) :
                   "The boards are set up so that they are slightly "
                   "off of the ground.  They look somewhat old, as "
                   "if they'd been set up a while ago.  They droop "
                   "down and hit the ground between supports.",
                ({ "plank supports","plank support","support",
                   "supports","chopped-up boards","chopped-up board",
                   "board","boards" }) :
                   "The boards are set up so that, on either end, there "
                   "is a support made of chopped-up boards.",
                ({ "larger path","path" }) :
              "A larger path goes off to the southeast.  There are "
                   "no planks going across it, but it is wider and "
                   "more travelled.",
           ]) );
   SetSmell( ([
                "default" : "Nature smells fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Some animals rustle in the distance.",
            ]) );
   SetExits( ([
                "northwest" : H_ROOM + "trail_01",
           ]) );
   AddExit("southeast",WORLD,(: PreExit :));
   SetInventory( ([
                    H_OBJ + "sign" : 1,
               ]) );
}

int PreExit() {
   if(this_player()->GetProperty("hikernoleave")) return 0;
   return 1;
}
