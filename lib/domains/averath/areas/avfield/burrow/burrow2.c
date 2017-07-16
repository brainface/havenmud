/* Averath Burrow2
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
   SetLong("The opening of the burrow lets in all the light "
           "available here. The walls are dirty brown and have "
           "some sort of residue smeared on them. They are "
           "all made up of compressed dirt and sand that "
           "has been formed, amazingly, into an even circular "
           "shape. There is a small fire pit in the center "
           "of the room. Directly south is a door which " 
           "if opened would lead further into the burrow. "
           "Travelling west would lead back towards the "
           "opening of the burrow. ");
SetItems( ([
      ({ "burrow" }) : (:GetLong:),
       ({ "opening" }) :
                 "Bright light is shining from the opening in "
                 "the distance. ",
            ({ "pit", "fire pit" }) :
                 "The small fire pit has some debris in the "
                 "bottom of it, but does not appear to have been "
                 "used in a very long time. ",
            ({ "residue", "slime" }) :
                 "The residue is a green slime and is smeared "
                 "along the walls.",
            ({ "wall","walls" }) :
                 "The walls are dirty brown and have "
                 "some sort of residue smeared on them. They are "
                 "all made up of compressed dirt and sand that has "
                 "has been formed amazingly into an even circular "
                  "shape.",
            ({ "floor", "ground" }) :
                 "The ground is made up of compressed sand and dirt. ",
            ({ "debris" }) :
                 "The debris is scattered about, covering the bottom "
                 "of the pit.",
           ({ "dirt", "sand" }) :
                 "The dirt and sand are compressed together making "
                 "walls of the burrow. They both are brown in "
                 "color and very rough to the touch.",
            ]) );
SetItemAdjectives( ([
  "slime" : ({"green"}),
          "pit" : ({ "fire", "small"}),
          "residue" : ({"green", "slime"}),
          "wall" : ({ "dirty", "brown", "circular"}),
          "dirt" : ({ "compressed", "brown", "rough"}),
          "tornado" : ({ "small", "sand"}),
          "debris" : ({ "ss"}),
]) );

SetExits( ([ "west" : AVB_BURROW + "burrow1", 
             "south" : AVB_BURROW + "burrow3",
        ]) );

SetListen( (["default" : "The sounds of swirling winds can be heard. ",
         ]) );
SetSmell( (["default" : "The air smells very moist here.",
        ]) );

SetInventory( ([ AVB_NPC + "centipede" : 1+random(2),
                 AVB_NPC + "water_beetle" : 1,
                 AVB_NPC + "caterpillar" : 2+random(2),
            ]) );
SetDoor("south", AVB_OBJ "square_door");
  call_other( AVB_OBJ "square_door", "SetClosed", 1);
  call_other( AVB_OBJ "square_door", "SetLocked", 1);

SetSearch( ([ "debris" : (: MySearch :) ]) );

}
string MySearch(object who) {
  object key = new(AVB_OBJ "triangle_key");

  if (!key) return "Searching doesn't reveal anything.";
  if (BeenSearched) return "The debris has recently been shuffled through.";
  send_messages( ({ "shuffle", "grab" }),
    "$agent_name $agent_verb through the debris for a moment "
    "then pauses to $agent_verb something.",
    who, 0, environment(who) );
  key->eventMove(who);
  BeenSearched += 1;
  return "You find a key under the debris.";
}
