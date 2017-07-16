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
  SetShort("a rocky canyon");
  SetLong("Rocks clutter the floor of the curving canyon as it weaves it's "
          "way deeper into the mountains.  Further south the crevice begins "
          "to open.");
  SetItems( ([({"curving canyon","crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"broken rocks","jagged rocks","rocks","broken rock","jagged rock","rock"}) : 
                "Jagged pieces of rock have fallen from the walls and "
                "cover the ground.",
              ({"floor"}) : 
                "Among the rocks on the floor an occasional bone fragment "
                "can be found.",
              ({"bone fragment","bone fragments"}) : 
                "The fragments have teeth marks and have had the marrow "
                "sucked out.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/old_troll" : 1,
              ]) );
  SetExits( ([
    "northwest" : VALLEY_ROOM + "/crevice_6",
    "south" : VALLEY_ROOM + "/crevice_9",
            ]) );
}
