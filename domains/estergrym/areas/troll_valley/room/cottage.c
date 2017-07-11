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
  SetShort("inside a cottage");
  SetLong("The domestic bliss, formerly associated with this quaint cabin, "
          "has been forever ruined by the devestation.  "
          "Splattered blood covers the curtains, furniture, and just about "
          "everything in sight.  What furniture that hasn't been "
          "broken, is tossed haphazardly around the place.  Even the once "
          "sturdy door is now broken and hanging off its twisted hinges.");         
  SetItems( ([({"broken door","door",}) :
		"The door has been "
                "ripped from its hinges.  Splintered claw marks are visible "
                "on its surface.",
              ({"broken hinges","broken hinge","hinge","hinges","twisted metal","metal"}) :
                "The hinges have been subjected to such force that they "
                "are not much more than twisted metal anymore.",
              ({"splintered claw mark","claw marks","claw marks","mark","marks"}) :
		"The surface of the broken door is marred by claw marks.  ",
              ({"quaint cabin","cabin","house","building"}) : 
                (string)GetLong(),
              ({"splattered blood","blood","dried blood"}) :
                "Several days old now, the blood has dried to an almost "
                "black color.  The curtains are stiff with it and it peels "
                "and cracks off of the solid sufaces.",
              ({"curtains","yellow curtains"}) : 
                "In between the splatters of blood a delicate floral "
                "pattern is sewn into the yellow curtains.",
              ({"furniture","broken furniture","fragments",
                "quality pieces","pieces"}) : 
                "The furniture really isn't much more than fragments now.  "
                "No craftsman would ever be able to turn this mess into "
                "the quality pieces that they once were.",
          ]) );
  SetInventory( ([
		VALLEY_NPC + "/raccoon" : 1,
              ]) );
  SetExits( ([
	"out" : VALLEY_ROOM + "/valley_w",
            ]) );
}


