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
  SetClimate("indoors");
  SetAmbientLight(12);
  SetShort("a dark cave");
  SetLong("At the end of a narrow curving passage, a small natural cavern "
          "exist, it's walls smooth and it's ceiling soot blackened.  "
          "A narrow beam of light comes in from a corner of the hole that "
          "seems to lead to the outside world.");
  SetItems( ([({"narrow curving passage","narrow passage","curving passage",
                "twisting passage","passage",}) : 
                "The twisting passage looks to lead up to the outside "
                "world.",
              ({"outside world","world"}) : 
                "It isn't visible from here, but perhaps the passage might "
                "lead there.",
              ({"small natural cavern","small cavern","natural cavern",
                "cavern","cave"}) : 
                (string)GetLong(),
              ({"smooth walls","walls"}) : 
                "For a natural cavern, the walls are amazingly uniform and "
                "smooth.",
              ({"soot blackened ceiling","black ceiling","ceiling"}) : 
                "The soot from many torches and fires has collected on the "
                "low roof.",
          ]) );
  SetInventory( ([
		VALLEY_OBJ + "/rock" : random(10),
		VALLEY_OBJ + "/orange" : 1,
		VALLEY_OBJ + "/kilt" : random(3),
		VALLEY_OBJ + "/bone" : random(5),
              ]) );
  SetExits( ([
    "out" : VALLEY_ROOM + "/crevice_9",
            ]) );
}

