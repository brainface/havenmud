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
  SetShort("a long stretch of canyon");
  SetLong("Stretching for quite a distance here, the canyon starts to "
          "widen to the southeast where it curves out of sight to the "
          "south.");
  SetItems( ([
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
    "northwest" : VALLEY_ROOM + "/crevice_2",
    "southeast" : VALLEY_ROOM + "/crevice_4",
            ]) );
}
