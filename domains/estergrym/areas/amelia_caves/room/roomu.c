// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a path through the cavern");
   SetLong("A path to the north leads through a small hole in the "
           "northern wall, and through that, you can see a small lake.  "
           "Here, however, the air is rather dry and the room rather "
           "dusty.  The path heads farther to the south, and enters another "
           "hole.");
   SetItems( ([
                ({ "main path","path" }) :
                   "The path comes from a hole in the northern "
                   "wall, and heads out through one in the southern.",
                ({ "south hole","hole" }) :
                   "The hole in the southern wall is fairly "
                   "small, but it seems to open up into some sort of room.",
                ({ "north hole","hole" }) :
                   "The hole in the northern wall is of a "
                   "small size, but it seems to open up into a large "
                   "open area.",
                ({ "small cavern","cavern" }) :
                   "The cavern is fairly small, as caverns go, but "
                   "manages to seem bigger than it really is when one "
                   "first looks.",
                ({ "small lake","lake" }) :
                   "The lake in the cavern to the north is fairly "
                   "small, but you can't make much more out from here.",
                ({ "northern wall","wall" }) :
                   "A small hole leaves to the more eastern side of the "
                   "northern wall.",
                ({ "southern wall","wall" }) :
                   "There is a hole in the southern wall much like the one "
                   "in the northern wall.",
                ({ "dusty room","room" }) :
                   "Two holes leave this dusty room, one to the north and "
                   "one to the south.",
           ]) );
   SetExits( ([
                "northeast" : C_ROOM + "roomt",
                "south" : C_ROOM + "roomv",
           ]) );
   SetInventory( ([
                    C_NPC + "bigbat" : 1,
                    C_NPC + "hmouse" : 2,
               ]) );
}
