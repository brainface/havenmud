#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise a little ways off to the west, and to the "
           "north after a simple building.  The grand donjon of the "
           "castle is to the south, but has no entrance here, while "
           "the much more plain building to the north has a large "
           "door in the middle of it.  To the east and west, the land is "
           "open for travel.");
   SetItems( ([
                ({ "simple building","plain building","building" }) :
                   "The building to the north is unadorned, made for "
                   "practical rather than aesthetic reasons.  Its "
                   "entrance is a large door in the middle of it.",
                ({ "grand donjon","donjon","largest building",
                   "building"}) :
                   "The donjon, south of here, is the largest "
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
                   "men to defend the castle from.  Far in the northwest, "
                   "a roofed area provides protection for archers to "
                   "shoot through narrow slits in the walls.",
           ]) );
 
   SetExits( ([
                "north" : VC_ROOM + "/armoury",
                "west"  : VC_ROOM + "/gen_01",
                "east"  : VC_ROOM + "/gen_03",
           ]) );

   SetInventory( ([
                    VC_NPC + "/serf" : random(2),
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
