/* the foyer
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a large foyer");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This large foyer is tiled in fine marble. The light from the "
          "skylights sparkles as it hits the clean tile. Overhead a large "
          "chandelier glitters beautifully. The entire room sparkles as if "
          "it was cleaned just for this occasion. To the west lies more or the "
          "foyer while to the east is what appears to be a library. To the "
          "south there seems to be a large ballroom.");
  SetItems( ([
      ({ "large foyer" "foyer" }) : (:GetLong:),
      ({ "fine marble" , "marble", "tile" }) : 
	     "This expensive tile glimmers in the light.",
      ({"large chandelier" , "chandelier" }) : 
	    "This large chandelier looks very expensive.",
      ({"skylights", "skylight"}) : 
	    "The skylights let in tremendous amounts of light.",
        "library" : "The library is to the east",
        "light" : "The light sparkles off the clean tile.",
      ]) );
  SetItemAdjectives( ([
         "fine marble" : ({ "clean" }),
                   ]) );
  SetExits( ([
        "west" : MANSION_ROOMS + "2a",
        "east" : MANSION_ROOMS + "4a",
        "south" : MANSION_ROOMS + "7a",
            ]) );
  SetListen( ([
        "default" : "The sounds of a party come from the south.",
           ]) );
  SetSmell( ([
       "default" : "The scent of cleaning products still lingers in the air.",
         ]) );
  SetInventory( ([
        MANSION_NPC + "butler" : 1,
        MANSION_NPC + "guard" : 1,
              ]) );
  }
