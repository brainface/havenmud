#include <lib.h> 
#include "../copse.h" 
inherit LIB_ROOM; 
 
static void create() { 
  room::create(); 
  SetShort("a thick concentration of cherry blossoms"); 
  SetLong("The thickness of the tress here makes it" 
          " difficult for one to see very far. The" 
          " ground is covered by a blanket of cherry" 
          " blossom petals and broken branches. To" 
          " the east the concentration of trees seems" 
          " to increase, while to the west it appears" 
          " to decrease slightly."); 
  SetItems( ([ 
      ({ "blossom", "cherry blossom", "tree", "trees" }) : 
      "These trees are responsible for the myriad of flower" 
      " petals found upon the path and surrounding area.", 
      ({ "petal", "petals" }) : 
      "These petals are of a light pink hue. Because there" 
      " are so many petals, it is hard to see the ground" 
      " beneath them.", 
      ({ "path", "ground" }) : 
      "The path seemingly winds between the cherry blossoms" 
      " but it is hard to tell because of the large number" 
      " of petals on the ground.", 
      ({ "branch", "branches" }) : 
      "The broken branches littering the ground look" 
      " as though they were forcibly removed from the trees" 
      " rather than falling off due to decay.", 
    ]) ); 
  SetItemAdjectives( ([ 
      "petals" : ({ "pink", "blossom", "cherry blossom" }), 
      "tree" : ({ "blossom", "cherry blossom" }), 
      "branch" : ({ "broken" }), 
    ]) ); 
  SetListen( ([ 
      "default" : "Light rustling noises sooth the copse.", 
    ]) ); 
  SetSmell( ([ 
      "default" :"The sweet aroma of cherry blossoms in bloom lingers here.", 
    ]) ); 
  SetInventory( ([ 
    COPSE_NPC + "caterpillar" : 4, 
    COPSE_NPC + "butterfly" : 1, 
    "/std/obj/tai_portal" :1, 
     
    ]) ); 
  SetExits( ([ 
      "west" : COPSE_ROOM "room5", 
      "east" : COPSE_ROOM "room7", 
    ]) ); 
} 
 
