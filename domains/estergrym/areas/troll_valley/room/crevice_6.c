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
  SetShort("a broad fissure");
  SetLong("The fissure here splits wide and opens into a great valley, "
          "littering the grass outside with broken rocks, fallen from the "
          "high walls.  The crevice winds its way both "
          "southeast and southwest out of sight.");
  SetItems( ([({"fissure","crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"broad bowl","bowl"}) : 
                "The walls from the canyon split away, forming a large bowl "
                "enclosing a beautiful green valley.",
              ({"beautiful green valley","beautiful valley","green valley",
                "valley","great valley"}) : 
                "Green grass and tiny fruit trees grow all about the "
                "valley.",
              ({"broken rocks","jagged rocks","rocks","broken rock","jagged rock","rock"}) : 
                "Jagged pieces of rock have fallen from the walls and "
                "cover the ground here, even extending out onto the grass "
                "of the valley to the northwest.",
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

          ]) );
  SetExits( ([
    "northwest" : VALLEY_ROOM + "/valley_s",
    "southeast" : VALLEY_ROOM + "/crevice_8",
    "southwest" : VALLEY_ROOM + "/crevice_7",
            ]) );
}
