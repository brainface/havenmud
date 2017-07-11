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
  SetShort("a fork in the canyon");
  SetLong("The crevice forks here with the wider branch continuing west and "
          "a much narrower one leading northwest.  Mountains made of dark "
          "rock can be seen on all sides.");
  SetItems( ([
              ({"wider branch","wide branch","west branch","branch"}) :
                "The canyon continues on to the west but curves away "
                "south, out of sight.",
              ({"narrower branch","narrow branch","northwest branch",
              "branch"}) :
                "The crevice is so narrow that one cannot really see what "
                "might be there.",
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
    "east" : VALLEY_ROOM + "/crack",
    "west" : VALLEY_ROOM + "/crevice_2",
    "northwest" :VALLEY_ROOM + "/crevice_d",
            ]) );
}
