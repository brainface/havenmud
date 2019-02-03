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
  SetShort("a broad curve in the canyon");
  SetLong("The canyon here makes a broad curve from the northwest to the "
          "south.  It has also widened to a point where the sky once again "
          "opens above.");
  SetItems( ([({"broad curve","curve"}) : 
                "The canyon widens as it curves here.  The walls still "
                "maintain their steepness though.",
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
		VALLEY_NPC + "/snake" : random(2),
              ]) );
  SetExits( ([
    "northwest" : VALLEY_ROOM + "/crevice_3",
    "south" : VALLEY_ROOM + "/crevice_5",
            ]) );
}
