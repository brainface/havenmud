#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("inside the tower");
   SetLong("Identical doors lead out to the north and east, both "
           "appearing strong and looking quite prepared for attacks upon "
           "the castle.  Stones have been laid in simple order to form "
           "this square, confining tower.  The main feature of the tower, "
           "however, is its staircase:  The steps go up in a simple "
           "manner, turning around and following up against the wall, "
           "but doing nothing other than that.  North, east and up are "
           "the only exits.");
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
                "north" : VC_ROOM + "/gen_09",
                "east"  : VC_ROOM + "/barracks",
                "up"    : VC_ROOM + "/tower_3b",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
