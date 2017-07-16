#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
  SetDomain("Valley");
   SetAmbientLight(50);   
   SetShort("the widow's cabin");
   SetLong("This small cabin looks quite comfortable and nice. A small table "
           "and chair sit off in the corner, and a fireplace sets near the "
           "back of the two room house. A child's toys litter the floor "
           "and turn the cabin into an obstacle course. There is another "
           "room to the south, as well as the door leading back out.");
   SetItems( ([ 
      ({ "two room house","small cabin","house","cabin" }) :
         "This is a small cabin, nestled deep in the woods.",
      ({ "small table","table" }) : 
         "A small table, skillfully crafted and sturdy. ",
      ({ "wooden chair","chair" }) : 
         "A wooden chair that appears to match the table. It looks homemade. ",
      ({ "corner" }) : 
         "A corner of the room, containing a table and chair.",
      ({ "fireplace","fire" }) :
         "A fire burns brightly here, and heats the small cabin very well.",
      ({ "child's toys","toys","toy","child's toy" }) :
         "Assorted toys to entertain a small child for hours. ",
      ({ "obstacle course" }) :
         "Dodging all the toys on the floor looks quite difficult.",
      ({ "floor" }) :
         "The floor of the cabin looks quite clean, enough so for a child to play "
         "without getting dirty.", 
      ({ "door" }) :
         "The door to the cabin is thick and sturdy.",   ]) );
   SetExits( ([ 
      "out" : PR_ROOM "/clearing", 
      "south" : PR_ROOM "/cabin2"
   ]) );
   SetInventory( ([ PR_NPC + "/widow" : 1,
                      PR_NPC + "/child" : 1  ]) );
}

