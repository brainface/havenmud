/* Averath Burrow6
*  Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

string MySearch(object who);
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
           "the room. A small fire pit sits in the middle of "
           "the room. Heading northeast would travel further into "
           "the burrow. Back northwest is a door, if opened, it "
           "would allow access back towards the opening of the "
           "burrow. ");
SetItems( ([
            ({ "pit", "fire pit" }) :
                 "The small fire pit has some debris in the "
                 "bottom of it, but does not appear to have been "
                 "used in a very long time. ",
            ({ "residue" }) :
                 "The residue is a green slime and is smeared "
                 "along the walls.",
            ({ "wall","walls" }) :
                 "The walls are dirty brown and have "
                 "some sort of residue smeared on them. They are "
                 "all made up of compressed dirt and sand that has "
                 "has been formed amazingly into an even circular "
                 "shape.",
           ({ "dirt", "sand" }) :
                 "The dirt and sand are compressed together making "
                 "walls of the burrow. They both are brown in "
                 "color and very rough to the touch.",
           ({ "debris" }) :
                 "The debris is scattered about, covering the bottom "
                 "of the pit.",
           ({ "animal carcasses", "carcass", "remnants" }) :
                   "The remnants look like old pieces of bug shells. ",
   ({ "burrow" }) : (:GetLong:),
           ({ "floor", "ground" }) :
                 "The ground is made up of compressed sand and dirt. ",
   ({ "crack", "cracks" }) :
                 "The small cracks allow some light to shine in. ",
            ]) );
SetItemAdjectives( ([
  "slime" : ({"green"}),
          "pit" : ({ "fire", "small"}),
          "residue" : ({"green", "slime"}),
          "wall" : ({ "dirty", "brown", "circular"}),
          "dirt" : ({ "compressed", "brown", "rough"}),
          "tornado" : ({ "small", "sand"}),
          "debris" : ({ "scattered"}),
]) );

SetExits( ([ "northeast" : AVB_BURROW + "burrow7",
             "northwest" : AVB_BURROW + "burrow5",
        ]) );
SetInventory( ([ AVB_NPC + "widow" : 2,
                 AVB_NPC + "water_beetle" : 1,
                 AVB_NPC + "centipede" : 2,
            ]) );
SetDoor("northwest", AVB_OBJ "circle_door");
  call_other( AVB_OBJ "circle_door", "SetClosed", 1);
  call_other( AVB_OBJ "circle_door", "SetLocked", 1);

SetSearch( ([ "debris" : (: MySearch :) ]) );

}
  string MySearch(object who) {
  if (BeenSearched) return "You find nothing.";
  send_messages( ({ "shuffle", "grab" }),
    "$agent_name $agent_verb through the debris for a moment "
    "and come away with nothing.",
    who, 0, environment(who) );
  BeenSearched += 0;
  return "You find nothing.";
}
