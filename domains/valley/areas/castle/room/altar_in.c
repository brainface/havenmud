#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(13);
   SetShort("in the altar");
   SetLong("A small cobweb hangs in the corner of the hollow altar, "
           "which isn't nearly so nice as it looks on the outside.  "
           "Bits of dust hang to the surfaces, even the walls of the "
           "altar.  Since the back is open, it is possible to leave "
           "by going out.");
   SetItems( ([
                ({ "hollow altar","altar" }) :
                   (: GetLong :),
                ({ "altar walls","corner","cobweb","bits of dust"
                   "bit of dust","surfaces","surface","dust","walls",
                   "wall","walls of the altar","wall of the altar",
                   "altar wall","small cobweb","back","cobwebs" }) :
                   "The walls of the altar, on this side, are dusty "
                   "and plain, and the corners have cobwebs hanging "
                   "in them.  The back, however, is open, allowing an "
                   "exit.",
           ]) );
   SetExits( ([
                "out"   : VC_ROOM + "/altar_at",
           ]) );
   SetInventory( ([
                    VC_NPC + "/girl2" : random(3)+2,
               ]) );
}
