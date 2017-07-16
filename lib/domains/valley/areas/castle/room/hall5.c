#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"
 
static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("an empty hallway");
   SetLong("The floor seems unusually cold, and the air unusually "
           "cramped for this castle.  The stones are still the same "
           "and the beams of wood stretching overhead are sturdy, but "
           "the hallway seems to be just filling space between one room "
           "and another.  There is a plain door to the east, and "
           "up against the wall, a stairway of dry wood heads downward.");
   SetItems( ([
                ({ "dry wooden stairway","wooden stairway","stairs",
                   "stair","staircase","stairway","dry wood",
                   "wood" }) :
                   "The stairs are made of a dry wood, cut roughly "
                   "and fragile.  They head down.",
                ({ "gray stones","stone","gray stone","stones",
                   "beams of wood","beam of wood","beam","beams",
                   "wooden beam","wooden beams","wall","walls" }) :
                   "The stones are uniform, and mostly the same general "
                   "shade of gray.  They seem rough and badly cut from "
                   "this side of the wall, but are probably all flat "
                   "and nice looking on the other side.  The wooden "
                   "beams hold up the walls, but are less finely "
                   "finished in here than outside.",
                ({ "empty hallway","hallway","hall","empty hall",
                   "castle" }) :
                   (: GetLong :),
                ({ "dusty floor","floor","dust" }) :
                   "Dust covers the floor off to the sides, but "
                   "in the direct line from the east door to the "
                   "staiway, the floor seems free of dust.",
           ]) );
   SetExits( ([
                "east" :  VC_ROOM + "/hall4",
                "down" :  VC_ROOM + "/hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant2" : 1,
                    VC_NPC + "/servant" : 2,
                    VC_NPC + "/slave_f" : 2,
               ]) );
}
