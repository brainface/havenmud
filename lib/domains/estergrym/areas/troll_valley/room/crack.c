/*
 * Coded by Godel@Haven
 * 7 February 1998
 *
 * Revised 04/99 by Gaby
 */

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;


static void create()
{
  room::create();
  SetClimate("mountains");
  SetShort("a narrow crevice");
  SetLong("A few yards north of the road the crack opens up into a fairly wide crevice that "
          "winds its way west through the mountains.");
  SetItems( ([
              ({"main road","road"}) :
                "Estergrym road can be seen to the east.",
              ({"crack"}) :
                (string)GetLong(),
              ({"wide crevice","fairly wide crevice","crevice","canyon",}) :
                "Unclimbable walls stretch high above forming a canyon "
                "that winds away to the west.",
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround crack.",
              ({"unclimbable walls","basalt walls","walls"}) : 
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) : 
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/small_lizard" : random(2),
              ]) );
  SetExits( ([
    "south" : "/domains/estergrym/virtual/grymxoria_road/25,0",
    "west" : VALLEY_ROOM + "/crevice_1",
            ]) );
}
