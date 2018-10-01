//  Malveillant Marketplace room 2
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("underground");
  SetShort("the marketplace");
  SetLong(
     "The marketplace is the hub of activity in Malveillant, constantly abuzz "
     "with the chitchat of vendors and shoppers alike. Shops of all size and "
     "variety nestle together in an outer ring which looks in on the center "
     "courtyard. The path is wide and covered in a soft moss and wild vines "
     "which spill over the half-wall that encloses the courtyard. The building "
     "here looks vacant, but the path curves towards more shops to the "
     "northeast and southeast."
     );
  SetListen( ([
     "default" : "Many voices plying wares can be heard in all directions.",
     ]) );
  SetSmell( ([
     "default" : "Scents ranging from freshly baked bread to the crisp smell "
    	 "of new clothing mingle in the air.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The moss and vine covered path curves towards the northeast and "
    	 "southeast.",
     ({"courtyard"}) :
         "The courtyard can be seen just beyond the half wall which circles "
         "it. ",
     ({"walls", "wall"}) : 
    	 "This is a half-wall, carved from obsidian, which partially "
         "encloses the courtyard. Lush, wild vines spill over the wall "
         "and creep out to the path.",
     ({"ground", "floor"}) : 
    	 "The ground is covered in overgrown clinging vines and a soft moss.",
     ({"moss"}) : 
    	 "The moss is soft and varies from a pale to dark green.",
     ({"vines", "vine"}) :
    	 "Small vines cling to the ground and walls, climbing over the wall "
    	 "and spilling into the courtyard.",
     ({"obsidian"}) :
    	 "A stone used frequently by the dark-elves, it is jet black in color "
         "and smooth and cool to the touch.",
     ({"shop", "shops", "building", "store"}) :
         "The building here looks as though it is empty and just waiting for "
         "someone to occupy it. All of the shops here nestle together in a "
         "large ring around the center courtyard.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "archway" : ({"carved", "obsidian"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     "building" : ({"vacant", "empty"}),
     ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
     "northeast" : MAL_ROOMS3 + "market1",
     "southeast" : MAL_ROOMS3 + "market3",
    ]) );
  SetEnters( ([
     "shop" : MAL_ROOMS3 + "empty",
     ]) );

}

