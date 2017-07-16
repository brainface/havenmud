#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the general store");
   SetLong("The thick boards that form the general store are "
           "made to keeps the weather and world out of this "
           "small area.  Thus are the goods and customers of "
           "the general store kepts dry and warm.  A door in the "
           "south leads out, but little else furnishes the "
           "room.");
   SetItems( ([
                ({ "thick boards","thick board","board","boards" }) :
                   "The boards are thick and sturdy, keeping out "
                   "the outside world, and in the inside one.  "
                   "Their orderly path is disrupted by a door "
                   "in the south wall.  Grainy lines cover some "
                   "sections of the wood, adding texture and life to it.",
                ({ "general store","store","room","area","small area" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/gen_04",
           ]) );
   SetInventory( ([
                    VC_NPC + "/general" : 1,
               ]) );
}
