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
  SetShort("a sharp curve in the canyon");
  SetLong("The crevice here cuts back sharply from the east to the southeast, "
          "leaving a narrow point of rock between.");
  SetItems( ([
              ({"narrow point of rock","narrow point","point",}) :
                "The cavern here turns so sharply that the inside curve is "
                "naught but a thin wall of rock stretching high over head.",
              ({"sharp curve","sharp turn","inside curve""curve","turn"}) :
                (string)GetLong(),
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
    "east" : VALLEY_ROOM + "/crevice_1",
    "southeast" : VALLEY_ROOM + "/crevice_3",
            ]) );
}
