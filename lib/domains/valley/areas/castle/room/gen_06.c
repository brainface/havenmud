#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise directly to the east, and to the north "
           "beyond an open space and a building which seems to be "
           "a part of the wall almost.  The grand donjon of the castle "
           "is to the west, but has no entrance here.  To the north and "
           "south, the land is open for travel.");
   SetItems( ([
                ({ "grand donjon","donjon","largest building",
                   "building"}) :
                   "The donjon, west of here, is the largest "
                   "building of all the castle, and the grandest "
                   "too.  However, there is no entrance here.",
                ({ "area","castle","land","open space","space" }) :
                   (: GetLong :),
                ({ "grand walls","castle walls","grand wall","castle wall",
                   "walls","wall","roofed area","archers","archer",
                   "narrow slit","narrow slits","slit","slits" }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.  To the far northeast, "
                   "a roofed area stands on the walls with what appear "
                   "to be narrow slits for arches in its walls.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gen_04",
                "south" : VC_ROOM + "/gen_07",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
