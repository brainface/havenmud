#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("inside a burial vault");
   SetLong("Some meek rays of light slink into the room from the east, "
           "where an opening leads out from this burial chamber.  "
           "The walls were built with many crevices for laying the dead "
           "inside of, and all are filled inside this room.  Burnt "
           "out torches line the walls.");
   SetItems( ([
                ({ "burnt out torches","burnt out torch","torch",
                   "torches","little stumps","little stump",
                   "stump","stumps" }) :
                   "The torches are little stumps of what they "
                   "used to be, when they still had spark and flame "
                   "left in them.",
                ({ "wall crevices","crevices","wall crevice",
                   "crevice","wall","walls","slot" }) :
                   "Dead bodies are inside each crevice of the walls, "
                   "one per slot.  The grimness of the room seems to be "
                   "reflected in the design of the walls.",
                ({ "dead bodies","dead body","body","bodies" }) :
                   "The dead range widely in age; some are very young and "
                   "others quiet old, having died in their dottage.",
                ({ "burial vault","vault","burial chamber","room",
                   "chamber" }) :
                   (: GetLong :),
                ({ "east opening","opening","meek rays of light",
                   "meek ray of light","rays of light","ray of light",
                   "meek ray","meek rays","rays","ray","light" }) :
                   "Some light enters the room with a great timidness "
                   "to it, as if it fears the though of existing down "
                   "here, in the earth, among the dead.  It comes in "
                   "through the opening to the east.",
           ]) );
   SetExits( ([
                "east" : VC_ROOM + "/c_hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_zombie" : 2+random(2),
                    VC_NPC + "/c_spook"  : 1+random(2),
               ]) );
}
