#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise to the north beyond a small structure, "
           "with little adornment beyond the boards it was built from.  "
           "The grand donjon of the castle is to the south, but has no "
           "entrance here, while a small door leads into the other "
           "building, north of here.  To the east and west, the land is "
           "open for travel.");
   SetItems( ([
                ({ "small structure","structure",
                   "building","other building","boards","board",
                   "small entrance","entrance" }) :
                   "The building north of here has a small entrance, "
                   "a door, which leads inside.  It has no decorations "
                   "or such upon it, but seems to be well made.",
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
                   "walls","wall" }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/tailor",
                "west"  : VC_ROOM + "/gen_02",
                "east"  : VC_ROOM + "/gen_04",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 3+random(2),
               ]) );
}
