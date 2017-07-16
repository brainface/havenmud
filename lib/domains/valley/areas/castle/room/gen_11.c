#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("High and mighty, the grand walls of the castle tower into the "
           "sky to the south, this open area going directly up to it.  "
           "Buildings presh against indents in the walls to the west "
           "and east, but there is no access to them here, and to the "
           "north the donjon sits complacently.  Travel is open to the "
           "east and west both.");
   SetItems( ([
                ({ "castle buildings","building in wall","building",
                   "buildings","donjon","chapel","barracks" }) :
                   "To the north, the grand building called the donjon "
                   "was built, while to the east is a chapel and to the "
                   "west the barracks for the castle Lord's army.",
                ({ "castle walls","castle wall","walls","wall",
                   "grand walls","grand wall" }) :
                   "To the south the castle walls rise into the air, "
                   "with a space on top to be walked upon.",
                ({ "castle","open area","area" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/gen_12",
                "west"  : VC_ROOM + "/gen_10",
           ]) );
   SetInventory( ([
                    VC_NPC + "/serf" : random(2),
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
