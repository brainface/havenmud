/* Averath Burrow3
*  Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

string SearchDebris();
int BeenSearched;

static void create() {
   room::create();
   BeenSearched = 0;
   SetShort("inside a large burrow");
   SetDomain("Averath");SetClimate("underground");
   SetLong("Small cracks in the dirty brown walls allow some "
           "light into this area. On some areas of the walls "
           "there are smeared residue spots. They are "
           "all made up of compressed dirt and sand that "
           "has been formed, amazingly, into an even circular "
           "shape. Small remnants of animal carcasses lay about "
           "the room. Heading west leads further into the "
           "burrow. North of here is a door, if opened, it "
           "would lead north back towards the opening of the "
           "burrow. ");
SetItems( ([
            ({ "residue", "spots" }) :
                 "The residue is a green slime and is smeared "
                 "along the walls.",
           ({ "crack", "cracks" }) :
                 "The small cracks allow some light to shine in. ",
  ({ "burrow" }) : (:GetLong:),
            ({ "wall","walls" }) :
                 "The walls are dirty brown and have "
           "some sort of residue smeared on them. They are "
                   "all made up of compressed dirt and sand that has "
                   "has been formed amazingly into an even circular "
                   "shape.",
            ({ "animal carcass", "carcasses", "remnants" }) :
                   "The remnants look like old pieces of bug shells. ",
            ({ "dirt", "sand" }) :
                 "The dirt and sand are compressed together making "
                 "walls of the burrow. They both are brown in "
                 "color and very rough to the touch.",
            ({ "floor", "ground" }) :
                 "The ground is made up of compressed sand and dirt. ",
            ]) );
SetItemAdjectives( ([
  "slime" : ({"green"}),

          "residue" : ({"green", "slime"}),
          "wall" : ({ "dirty", "brown", "circular"}),
          "dirt" : ({ "compressed", "brown", "rough"}),
  "cracks" : ({"small"}),
]) );

SetExits( ([ "north" : AVB_BURROW + "burrow2",
             "west" : AVB_BURROW + "burrow4",
        ]) );
SetInventory( ([ AVB_NPC + "widow" : 2,
                 AVB_NPC + "water_beetle" : 1,
                 AVB_NPC + "centipede" : 2,
            ]) );
SetDoor("north", AVB_OBJ "square_door");
  call_other( AVB_OBJ "square_door", "SetClosed", 1);
  call_other( AVB_OBJ "square_door", "SetLocked", 1);
}
