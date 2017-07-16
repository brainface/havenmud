//  Hat Shop for Marketplace, Future use possible
//  No vendor currently in plan 
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("malveillant hat shop");
  SetLong(
     "A long polished counter lines the far wall of this small shop. Numerous "
     "short stands sit atop the counter, with a few hats resting on them. It "
     "seems the shop hasn't fully opened, as near the stairway sit several "
     "boxes which contain carefully wrapped hats. The hat displays are only "
     "half set up, and there is no shopkeeper in sight. The narrow stairway "
     "leads back down to the boutique."
     );
  SetListen( ([
     "default" : "Quiet voices can be heard from downstairs.",
     ]) );
  SetSmell( ([
     "default" : "The air vaguely smells of roses.",
     ]) );
  SetItems( ([
     ({"shop", "store", "room"}) : (:GetLong:),
     ({"counter"}) :
     	 "The counter is long and the top is covered in polished obsidian. "
     	 "Short hat stands rest on the counter, but it hasn't been set up "
     	 "completely.",
     ({"stand", "stands", "display", "displays"}) :
     	 "The hat stands are made of metal and sit atop the counter where they "
     	 "each hold a hat. Some stands are empty and none of the displays are "
     	 "completed.",
     ({"hat", "hats"}) :
     	 "Regal looking hats with feathers, berets, top hats, and various other "
     	 "styles rest atop the hat stands on the counter, and sit untouched in "
     	 "boxes near the stairs.",
     ({"stairs", "stairway"}) :
     	 "The narrow stairway leads back down to Mari Laviste's boutique.",
     ({"box", "boxes"}) :
     	 "Several boxes sit in varying states of being unpacked, filled with "
     	 "carefully wrapped hats.",
    ({"floor", "ground"}) :
         "The floor clean and tidy, except for a few boxes.",
    ({"walls", "wall"}) : 
    	"The walls are bare.",    
     ]) );  
  SetItemAdjectives( ([
     "counter" : ({"long", "polished"}),
     "stand" : ({"short", "metal"}),
     "stairs" : ({"narrow"}),
      ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "down" : MAL_ROOMS3 + "clothier",
     ]) );



}

