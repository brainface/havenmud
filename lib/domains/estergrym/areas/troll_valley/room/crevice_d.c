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
  SetShort("a dead end");
  SetLong("The canyon here narrows to a point that it cannot be traversed "
          "further.  It does however, widen in the southeast into the main "
          "channel again.");
  SetItems( ([
              ({"dead end"}) :
                "The two walls of the canyon narrow and join forming a "
                "sharp dead end.",
              ({"main channel","channel"}) :
                "Though extremely narrow here, one can just see a much "
                "larger channel of the canyon to the southeast.",
              ({"crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/snake" : random(2),
              ]) );
  SetExits( ([
    "southeast" : VALLEY_ROOM + "/crevice_1",
            ]) );
}
