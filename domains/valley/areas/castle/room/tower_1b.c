#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("on the stairs");
   SetLong("The staircase continues to go around the edges of the wall, "
           "heading in both the up and the down directions.  The "
           "gray stones and square fashion of the tower give it a "
           "blocky air, and as the space is also very small, it is "
           "confining and clausterphobic as well.");
   SetItems( ([
                ({ "gray stones","stone","stones","wall",
                   "walls" }) :
                   "Each stone has been put in place in a simple, "
                   "orderly manner.  Most are fairly rough, and grainy, "
                   "but fit well in the walls.",
                ({ "castle staircase","staircase","stairs","stair",
                   "step","steps","castle","tower",
                   "space" }) :
                   (: GetLong :),
           ]) );
   SetItemAdjectives( ([
                         "stones" : ({ "grey","gray" }),
                         "staircase" : ({ "castle","square","grey" }),
                    ]) );
   SetExits( ([
                "down"  : VC_ROOM + "/tower_1a",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
