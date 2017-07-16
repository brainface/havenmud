#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Grand walls rise directly to the east, with an area leading up "
           "to the gates entering it.  There appears to be a portcullis "
           "attached to the walls somehow, forming the gate, but "
           "it is still distant from here.  To the west, two large "
           "doors lead into the donjon, the main building of the castle.  "
           "To the north and south, the land is open for travel.");
   SetItems( ([
                ({ "grand donjon","donjon","largest building",
                   "building"}) :
                   "The donjon, west of here, is the largest "
                   "building of all the castle, and the grandest "
                   "too.  A set of large double doors leads into the "
                   "building.",
                ({ "area","castle","land","open space","space" }) :
                   (: GetLong :),
                ({ "grand walls","castle walls","grand wall","castle wall",
                   "walls","wall" }) :
                   "The walls are thick and tall, with room on top for "
                   "men to defend the castle from.  To the east are "
                   "the gates for entering and exiting the castle.  "
                   "A portcullis bars the way.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gen_06",
                "south" : VC_ROOM + "/gen_08",
                "west"  : VC_ROOM + "/ent",
                "east"  : VC_ROOM + "/gate",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
