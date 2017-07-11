#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetShort("inside the castle walls");
   SetLong("Open space continues to the north and west, stretching out "
           "leisurely but with consideration of space.  To the east, "
           "great walls rise into the air, and a small nook leads into "
           "them, presumably heading towards the tower which pokes up "
           "into the air, small slits in its walls as windows.  To the "
           "south the walls are also present, but beyond a tidy "
           "building built of solid gray bricks.  A wooden door leads "
           "into the building.  The donjon is to the northwest, but "
           "has no entrance here.");
   SetItems( ([
                ({ "grand donjon","donjon","building","main building" }) :
                   "The donjon is the main building of the castle, the "
                   "largest and grandest of it as well.",
                ({ "tidy chapel","chapel","tidy building","building",
                   "solid gray bricks","solid gray brick","solid brick",
                   "solid bricks","gray bricks","gray brick","brick",
                   "bricks","solid grey bricks","solid grey brick",
                   "grey bricks","grey brick" }) :
                   "The building to the south is made of thick boards, "
                   "put together in a neat and tidy fashion up against "
                   "the castle walls.  A basic door appears in it "
                   "here, allowing entrance into the chapel.",
                ({ "southeast tower","tower","small slits","small slit",
                   "slit","slits","window","windows","roof","thin slit",
                   "thin slits" }) :
                   "The tower is rather square and stocky, but provides "
                   "an area sheltered from things like rain and "
                   "fastly moving arrows, allowing archers to shoot from "
                   "the thin slits they consider to be enough window "
                   "to shoot from.",
                ({ "open space","space","castle" }) :
                   (: GetLong :),
                ({ "great walls","castle walls","great wall","castle wall",
                   "wall","walls","small nook","nook" }) :
                   "The walls are tough, very solid and strong and thick, "
                   "with an area on top for soliders to stand.  They "
                   "exist to the east and south; though to the south it "
                   "is beyond the chapel.  In the east one, a small "
                   "nook has been carefully made to lead into the tower.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gen_08",
                "south" : VC_ROOM + "/chapel",
                "east"  : VC_ROOM + "/gen_13",
                "west"  : VC_ROOM + "/gen_11",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
