#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("inside the tower");
   SetLong("Stones have been laid in simple order to form this square, "
           "confining tower.  A door leads out to the south, and appears "
           "strong and prepared for attacks upon the castle.  The main "
           "feature of the tower, however, is its staircase:  The "
           "steps go up in a simple manner, turning around and following "
           "up against the wall, but doing nothing other than that.  "
           "South and up are the only exits.");
   SetItems( ([
                ({ "ordered stones","stone","stones" }) :
                   "The stones make up the tower, causing it to be "
                   "secure and complete.",
                ({ "square confining tower","tower","confining tower",
                   "confining square tower","square tower","castle",
                   "staircase","stairs","stair","steps","step","wall" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/gen_05",
                "up"    : VC_ROOM + "/tower_1b",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
