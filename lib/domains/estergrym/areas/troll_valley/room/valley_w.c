/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;


static void create()
{
  room::create();
  SetClimate("mountains");
  SetShort("outside a cottage");
  SetLong("A quaint little cottage rests here at the west end of the green "
          "valley.  Fruit trees dot the area, providing a break to the "
          "near perfect grass.");
  SetItems( ([({"broad bowl","bowl"}) : 
                "The valley appears completely enclosed in a wall of "
                "mountains.",
              ({"beautiful green valley","beautiful valley","green valley",
                "valley"}) : 
                "Green grass and tiny fruit trees grow all about the "
                "valley.",
              ({"bright green grass","green grass","perfect green grass","perfect grass",
                "grass"}) : 
                "Bright green and incredibly even, the grass has a "
                "cultivated look to it.",
              ({"tiny fruit trees","fruit trees","trees","clumps"}) : 
                "Growing in neat little clumps, it is obvious that the "
                "trees have been cultivated here.",
              ({"apple tree","tree"}) : 
                "Bright apples grow high on the tree, occasionally one "
                "might fall to the ground.",
              ({"peach tree","tree"}) : 
                "Fuzzy peaches dangle just out of reach from the healthy "
                "tree.",
              ({"orange tree","tree"}) : 
                "Ripe oranges gleam like the sun, hanging all over the "
                "tree.",
              ({"small plum tree","plum tree","small tree","tree"}) : 
                "Purple plums hang ripening on the small plum tree.",
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"quaint little cottage","stone cottage","stone house",
                "cottage","house","quaint cottage","little cottage",}) : 
                "A bright red roof tops the stone cottage, but the door "
                "has been torn from its hinges.",
              ({"bright red painted roof","red painted roof","bright painted roof","bright red roof","painted roof","bright roof","red roof","roof"}) : 
                "The roof is bright enought that it has to have been "
                "painted in the last year.",
              ({"broken door","door",}) : 
                "Ripped from its hinges, splintered claw marks are visible "
                "on its surface.",
              ({"broken hinges","broken hinge","hinge","hinges","twisted metal","metal"}) : 
                "The hinges have been subjected to such force that they "
                "not much more than twisted metal anymore.",
              ({"splintered claw mark","claw marks","claw marks","mark","marks"}) : 
                "The surface of the broken door is marred by the claw marks "
                "of a creature with huge hands/paws?",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/dwarven_soldier" : random(3),
		VALLEY_OBJ + "/apple" : 1 + random(2),
		VALLEY_OBJ + "/peach" : 1 +random(2),
		VALLEY_OBJ + "/orange" : random(2),
		VALLEY_OBJ + "/plum" : 1+ random(2),
              ]) );
  SetExits( ([
    "north" : VALLEY_ROOM + "/valley_nw",
    "east" : VALLEY_ROOM + "/valley_c",
    "southeast" : VALLEY_ROOM + "/valley_s",
            ]) );
  SetEnters( ([
    "cottage" : VALLEY_ROOM + "/cottage",
           ]) );
}
