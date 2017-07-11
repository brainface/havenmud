#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise directly to the west, and to the north "
           "behind a stocky building as well.  The grand donjon of the "
           "castle is to the south, and a dingy, battered door enters "
           "it from here, while the northern building's doorway is "
           "without any covering at all.  To the east, the land is "
           "open for travel.");
   SetItems( ([
                ({ "grand donjon","donjon","largest building",
                   "building" }) :
                   "The donjon, south of here, is the largest "
                   "building of all the castle, and the grandest "
                   "too.  However, the door that leads into it "
                   "appears to have little glory to it, as it is "
                   "probably used by the serfs, servants, and slaves "
                   "that might serve in the cookhouse north of here.",
                ({ "stocky building","cookhouse","house","building",
                   "northern building",
                      }) :
                   "The building to the north seems to be frequently "
                   "used, and the demeaner is that of a cookhouse.",
                ({ "area","castle","land" }) :
                   (: GetLong :),
                ({ "grand walls","castle walls","grand wall","castle wall",
                   "walls","wall","roofed area","archers","archer",
                   "narrow slit","narrow slits","slit","slits", }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.  In the northwest, "
                   "a roofed area provides protection for archers to "
                   "shoot through narrow slits in the walls.",
           ]) );
   SetListen( ([
                 "default" : "Clattering noises come from the cookhouse.",
            ]) );
   SetExits( ([
                "north" : VC_ROOM + "/cook",
                "south" : VC_ROOM + "/someroom",
                "east"  : VC_ROOM + "/gen_02",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 3+random(2),
               ]) );
}
