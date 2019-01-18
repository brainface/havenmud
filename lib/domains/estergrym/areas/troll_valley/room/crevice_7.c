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
  SetShort("a filthy den");
  SetLong("Offal, bones and other disgusting things litter the ground "
          "here and hang from just about every crag in sight.  The canyon "
          "comes to an abrupt and wide end here.  Someone has set up "
          "'home' here.");
  SetItems( ([({"home","crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"broken rocks","jagged rocks","jagged points","rocks","broken rock","jagged rock","rock"}) : 
                "Jagged pieces of rock have fallen from the walls and "
                "cover the ground here.",
              ({"offal","disgusting things","dried organs","dried organ","things","rotting organs",
                "organs","waste products","waste",}) : 
                "Dried and rotting organs and waste products cover the "
                "area here.  It looks as though something has "
                "intentionally splattered them everywhere.",
              ({"crag",}) : 
                "Jagged points project from the rock here."
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/filthy_troll" : 1,
		VALLEY_OBJ + "/bone" : random(3),
              ]) );
  SetExits( ([
    "northeast" : VALLEY_ROOM + "/crevice_6",
            ]) );
}
