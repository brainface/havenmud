#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("near the wall");
   SetLong("Tall and mighty, the wall encircling this castle "
           "almost appears to grow out of the ground to the west.  "
           "To the north, the donjon, the largest building inside "
           "these castle walls, shows a little bit of itself, "
           "while to the south is a square tower with one door in "
           "it.  Its walls continue to the east as part of another "
           "building, forming the edges of the open land that is "
           "walkable.");
   SetItems( ([
                ({ "square tower","tower","gray stones","grey stones",
                   "gray stone","grey stone","stone","stones" }) :
                   "The square tower is blocky, but very solid, made "
                   "of the same gray stones that the donjon is.  A "
                   "strong door leads into it.",
                ({ "tall mighty wall","tall wall","mighty wall",
                   "castle wall","wall","castle walls",
                   "walls" }) :
                   "The walls are grand, very solid and thick looking.  "
                   "The tower is attached to it, forming a part of "
                   "it in fact, as it protects the castle.",
                ({ "castle","ground","open land","land" }) :
                   (: GetLong :),
                ({ "largest building","building","donjon","large building",
                   "grand building","grandest building","gray stones",
                   "gray stone","grey stone","grey stones","stone",
                   "stones" }) :
                   "The building to the north is grand and solid, "
                   "made of many gray stones.  It, the donjon, "
                   "is the largest and grandest building of all those "
                   "building inside these walls.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/tower_3a",
                "east"  : VC_ROOM + "/gen_10",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
