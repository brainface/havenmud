/* Averath Burrow8
*  Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;


static void create() {
   room::create();
   SetShort("inside a large burrow");
   SetDomain("Averath");SetClimate("indoors");SetClimate("underground");
   SetLong("Some light is let in from small cracks in the "
           "dirty brown residue stained walls. They are all "
           "made up of compressed dirt and sand that has been formed, "
           "amazingly, into an even circular shape. Small "
           "remnants of animal carcasses lay about the room. "
           "A door lies north, if opened, it would allow "
           "further travel into the burrow. While south "
           "would lead back towards the opening. ");
SetItems( ([
            ({ "residue", "stain" }) :
                 "The residue is a stained green slime and is smeared "
                 "into the walls.",
            ({ "wall","walls" }) :
                 "The walls are dirty brown and have "
                 "some sort of residue smeared on them. They are "
                 "all made up of compressed dirt and sand that has "
                 "has been formed amazingly into an even circular "
                 "shape.",
            ({ "animal carcasses", "carcass", "remnants" }) :
                   "The remnants look like old pieces of bug shells. ",
            ({ "dirt", "sand" }) :
                 "The dirt and sand are compressed together making "
                 "walls of the burrow. They both are brown in "
                 "color and very rough to the touch.",
            ({ "floor", "ground" }) :
                 "The ground is made up of compressed sand and dirt. ",
            ({ "burrow" }) : (:GetLong:),
            ]) );
SetItemAdjectives( ([
          "slime" : ({ "green", "smeared" }),
          "wall" : ({ "dirty", "stained", "brown", "circular"}),
          "cracks" : ({ "small" }),         
          "dirt" : ({ "brown", "compressed", "rough"}),
                 ] ) );
SetExits( ([ "north" : AVB_BURROW + "chamber",
             "south" : AVB_BURROW + "burrow7",
        ]) );
SetInventory( ([ AVB_NPC + "widow" : 2,
                 AVB_NPC + "caterpillar" : 3,
            ]) );
SetDoor("north", AVB_OBJ "triangle_door");
  call_other( AVB_OBJ "circle_door", "SetClosed", 1);
  call_other( AVB_OBJ "circle_door", "SetLocked", 1);
}
