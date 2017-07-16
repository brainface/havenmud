#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("an empty hallway");
   SetLong("The stones are still the same and the beams of wood "
           "stretching overhead are sturdy, but the hallway seems to be "
           "just filling space between one room and another.  The floor "
           "seems unusually cold, and the air unusually cramped for this "
           "castle.  There is a plain door to the east, and up against "
           "the wall, a stairway of dry wood heads upward.  A thin "
           "hall leads north.");
   SetItems( ([
                ({ "dry wooden stairway","wooden stairway","stairs",
                   "stair","staircase","stairway","dry wood",
                   "wood" }) :
                   "The stairs are made of a dry wood, cut roughly "
                   "and fragile.  A trapdoor hides under the staircase, "
                   "leading down.",
                ({ "gray stones","stone","gray stone","stones",
                   "beams of wood","beam of wood","beam","beams",
                   "wooden beam","wooden beams","wall","walls" }) :
                   "The stones are uniform, and mostly the same general "
                   "shade of gray.  They seem rough and badly cut from "
                   "this side of the wall, but are probably all flat "
                   "and nice looking on the other side.  The wooden "
                   "beams hold up the walls, but are less finely "
                   "finished in here than outside.",
                ({ "empty hallway","thin hall","hallway","hall",
                   "empty hall","castle" }) :
                   (: GetLong :),
                ({ "dusty floor","floor","dust" }) :
                   "Dust covers the floor off to the sides, but "
                   "in the direct line from the east door to the "
                   "staiway, the floor seems free of dust.",
           ]) );
   SetExits( ([
                "east"  :  VC_ROOM + "/hall1",
                "up"    :  VC_ROOM + "/hall5",
                "down"  :  VC_ROOM + "/slave",
                "north" :  VC_ROOM + "/someroom",
           ]) );
   SetInventory( ([
                    VC_NPC + "/slave_m" : random(2),
                    VC_NPC + "/slave_f" : 2,
               ]) );
}
