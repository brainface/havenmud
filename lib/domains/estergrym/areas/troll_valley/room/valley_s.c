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
  SetShort("near a fissure in the rock");
  SetLong("A broad fissure opens into the wall of rock here that makes up "
          "the wall around the valley.  Rocks lay strewn about the grass, "
          "kicked from just inside the opening.  Broken limbs of trees "
          "litter the area.");
  SetItems( ([({"broad bowl","bowl"}) : 
                "The walls from the canyon split away, forming a large bowl "
                "enclosing a beautiful green valley.",
              ({"fissure","opening","crack"}) : 
                "A broad crack opens here leading into yet another canyon.",
              ({"canyon","crevice"}) : 
                "The dark crevice splits, and curves too much for "
                "visibility.",
              ({"bright green grass","green grass","grass"}) : 
                "Bright green and incredibly even, the grass has a "
                "cultivated look to it.  Unfortunately, jagged rocks "
                "clutter the area.",
              ({"tiny fruit trees","fruit trees","fruit tree","trees","cultivated trees",
                "clumps"}) : 
                "Growing in neat little clumps, it is obvious that the "
                "trees have been cultivated here.  Many however have had "
                "limbs ripped from them.",
              ({"apple tree","tree"}) : 
                "Bright apples grow high on the tree, occasionally one "
                "might fall to the ground.",
              ({"peach tree","tree"}) : 
                "The trunk twisted nearly in two, all of the fruit has "
                "fallen away from the tree.",
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
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/dwarven_soldier" : random(4) + 2,
		VALLEY_NPC + "/dwarven_leader" : 1,
		VALLEY_NPC + "/hunting_dog" : 1,
		VALLEY_OBJ + "/apple" : random(2),
		VALLEY_OBJ + "/peach" : random(4),
		VALLEY_OBJ + "/orange" : 2 + random(2),
		VALLEY_OBJ + "/plum" : random(2),
		VALLEY_OBJ + "/limb" : random(4) + 1,
		VALLEY_OBJ + "/rock" : random(4) + 1,
              ]) );
  SetExits( ([
    "north" : VALLEY_ROOM + "/valley_c",
    "northwest" : VALLEY_ROOM + "/valley_w",
            ]) );
  SetEnters( ([
    "fissure" : VALLEY_ROOM + "/crevice_6",
           ]) );
}
