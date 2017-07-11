#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise a little ways off to the west, and to the "
           "south beyond what looks to be a military building.  The grand "
           "donjon of the castle is to the north, but has no entrance "
           "here, while there is a very sturdy door leading into the "
           "barracks to the south.  To the east and west, the land is "
           "open for travel.");
   SetItems( ([
                ({ "military building","barracks","building" }) :
                   "The building to the south has the bearing of an "
                   "army's office, and is probably the barracks for the "
                   "castle Lord's personal army.  A solid door leads into "
                   "it directly south from here.",
                ({ "grand donjon","donjon","largest building",
                   "building"}) :
                   "The donjon, north of here, is the largest "
                   "building of all the castle, and the grandest "
                   "too.  It extends to both west and east, while other "
                   "buildings have only one floor and fill a smaller "
                   "space.",
                ({ "area","castle","land" }) :
                   (: GetLong :),
                ({ "grand walls","castle walls","grand wall","castle wall",
                   "walls","wall","roofed area","archers","archer",
                   "narrow slit","narrow slits","slit","slits" }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.  Far in the southwest, "
                   "a roofed area provides protection for archers to "
                   "shoot through narrow slits in the walls.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/barracks",
                "west"  : VC_ROOM + "/gen_09",
                "east"  : VC_ROOM + "/gen_11",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
