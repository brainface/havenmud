#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise directly to the east, and to the north "
           "behind a building which is almost tucked right into "
           "it.  The grand donjon of the castle is to the southwest, "
           "but has no entrance here, while the building to the north "
           "has a stout door as its entrance.  To the east, the thick "
           "walls have an opening inside of them, presumably heading "
           "into the tower.  To the west, "
           "the land is open for travel.  The building to the "
           "north has a door in it as an entrance.");
   SetItems( ([
                ({ "grand donjon","donjon","largest building",
                   "building"}) :
                   "The donjon, south of here, is the largest "
                   "building of all the castle, and the grandest "
                   "too.  However, there is no entrance here.",
                ({ "stocky building","house","building",
                   "northern building" }) :
                   "The building to the north seems to be fairly "
                   "calm in demeaner, silently going along on its own "
                   "business while the rest of the castle runs around.  "
                   "A plain door leads into it.",
                ({ "area","castle","land" }) :
                   (: GetLong :),
                ({ "grand walls","castle walls","grand wall","castle wall",
                   "walls","wall","roofed area","archers","archer",
                   "narrow slit","narrow slits","slit","slits" }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.  In the northeast, "
                   "a roofed area provides protection for archers to "
                   "shoot through narrow slits in the walls.",
           ]) );
   SetListen( ([
                 "default" : "The air around here is calm and quiet.",
            ]) );
   SetExits( ([
                "north" : VC_ROOM + "/general",
                "south" : VC_ROOM + "/gen_06",
                "east"  : VC_ROOM + "/gen_05",
                "west"  : VC_ROOM + "/gen_03",
           ]) );
   SetInventory( ([
                    VC_NPC + "/serf" : random(2),
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
