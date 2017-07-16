#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the living room");
   SetLong("Worn carpet covers the floor of the living room of the "
           "farm house.  An old sofa sits up against the bottom "
           "of a window in the south of the house, which peers out "
           "at the Ruined Sea.  A doorway to the west stands open for "
           "movement, and to the north it is possible to leave the "
           "house and enter the yard.");
   SetItems( ([
                ({ "farm house","house","farm","yard","west door" }) :
                   "It is impossible to see that from this angle.",
                ({ "west doorway","doorway" }) :
                   "The door is not attached to it currently.",
                ({ "north doorway","north door","door","doorway" }) :
                   "The doorway to the north has a door, but it isn't "
                   "much of one.  It's barely connected anymore, and "
                   "hangs at a funny angle.",
                ({ "south window","window" }) :
                   "The Ruined Sea is visable through the window.",
                ({ "ruined sea","sea" }) :
                   "The Ruined Sea is desolate of all life.",
                ({ "living room","room" }) : (: GetLong :),
                ({ "worn carpet","carpet" }) :
                   "The carpet is old and shaggy, and looks very "
                   "dirty too.",
                ({ "old sofa","sofa" }) :
                   "An ugly floral pattern in many hues covers the "
                   "sofa.",
                ({ "ugly floral pattern","ugly pattern","floral pattern" }) :
                   "The pattern is much like one you'd find in a yard "
                   "sale.",
           ]) );
   SetExits( ([
                "north" : SDM_ROOM + "/yard",
                "west" : SDM_ROOM + "/kitchen",
           ]) );
   SetObviousExits("north, west");
   SetInventory( ([
                    SDM_NPC + "/son" : 1,
                    SDM_NPC + "/father" : 1,
               ]) );
}