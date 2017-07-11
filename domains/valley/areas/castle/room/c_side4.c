#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("inside a burial vault");
   SetLong("The stone walls are old, yet still sturdy and well made; "
           "the recesses for the dead have yet to show any signs of "
           "crumbling apart and falling in on their guests for eternity.  "
           "A door in the west wall is the only exit.  A torch glows "
           "dully in the back of the room.");
   SetItems( ([
                ({ "glowing torch","torch" }) :
                   "The torch glows sullenly, its efforts quiet "
                   "dampened due to the fact that it is nearly "
                   "burned out.",
                ({ "burial vault","vault","room" }) :
                   (: GetLong :),
                ({ "stone walls","stone wall","wall","walls","recesses",
                   "recess","simple gray stone","gray stone","stone",
                   "simple stone","dead","west wall" }) :
                   "The walls are made of a simple gray stone, "
                   "and show no interesting charactoristics aside "
                   "from the recesses for holding the dead.  The dead, "
                   "for their part, rest quietly in their holding "
                   "places.  A torch glows in the back of the room, "
                   "mounted upon the wall.",
           ]) );
   SetExits( ([
                "west" : VC_ROOM + "/c_hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_shade" : 2,
                    VC_NPC + "/c_skel" : 1,
               ]) );
}
