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
  SetShort("an opening to a valley");
  SetLong("The high walls of the canyon spread away forming the beginnings "
          "of a broad bowl in the mountains housing a beautiful valley.");
  SetItems( ([({"broad bowl","bowl"}) : 
                "The walls from the canyon split away, forming a large bowl "
                "enclosing a beautiful green valley.",
              ({"beautiful green valley","beautiful valley","green valley",
                "valley"}) : 
                "Green grass and tiny fruit trees grow all about the "
                "valley.",
              ({"bright green grass","green grass","grass"}) : 
                "Bright green and incredibly even, the grass has a "
                "cultivated look to it.",
              ({"tiny fruit trees","tiny fruit tree","fruit trees",
                "fruit tree","trees","tree","clumps"}) : 
                "Growing in neat little clumps, it is obvious that the "
                "trees have been cultivated here.",
              ({"fruit"}) : 
                "It is much too far off to tell what type of fruit grows "
                "on the trees.",
              ({"crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/small_lizard" : random(2),
              ]) );
  SetExits( ([
    "north" : VALLEY_ROOM + "/crevice_4",
    "southwest" : VALLEY_ROOM + "/valley_nw",
            ]) );
}
