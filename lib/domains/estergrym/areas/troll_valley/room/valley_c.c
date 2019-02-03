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
  SetClimate("temperate");
  SetShort("a beautiful valley");
  SetLong("In the distance to the west a cottage rests, completing the "
          "image of perfection here in the valley.  In between here and "
          "there stretch acres of grass, decorated only by an "
          "occasional fruit tree.");
  SetItems( ([({"broad bowl","bowl"}) : 
                "The walls from the canyon split away, forming a large bowl "
                "enclosing a beautiful green valley.",
              ({"bright green grass","green grass","grass"}) : 
                "Bright green and incredibly even, the grass has a "
                "cultivated look to it.",
              ({"tiny fruit trees","fruit trees","fruit tree","trees","cultivated trees",
                "clumps"}) : 
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
              ({"beautiful green valley","beautiful valley","green valley",
                "valley"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"stone cottage","stone house","cottage","house"}) : 
                "A bright red roof tops the stone cottage.",
              ({"bright red painted roof","red painted roof","bright painted roof","bright red roof","painted roof","bright roof","red roof","roof"}) : 
                "The roof is bright enought that it has to have been "
                "painted in the last year.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/dwarven_soldier" : random(5),
		VALLEY_OBJ + "/apple"  : 1  + random(2),
		VALLEY_OBJ + "/peach"  : 1 + random(2),
		VALLEY_OBJ + "/orange" : 1 + random(2),
		VALLEY_OBJ + "/plum"   : 1 + random(2),
              ]) );
  SetExits( ([
    "northwest" : VALLEY_ROOM + "/valley_nw",
    "west" : VALLEY_ROOM + "/valley_w",
    "south" : VALLEY_ROOM + "/valley_s",
            ]) );
}
