#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("bedchamber");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with a slight amount of artificial"
    " modification.  There are a few crimson rags hanging here,"
    " serving as crude curtains.  In the center of the"
    " chamber there is a small pallet that serves as a bed.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"curtains","rags","crude curtains","crimson rags","rag","curtain"}) :
      "These nearly rotted scraps of fabric are musty and filled "
      "with holes.",
     ({"bed","pallet","small pallet"}) : 
      "A primitive looking bundle of straw and wool that looks "
      "rather uncomfortable lies in the center of the chamber."          
    ]) );  
  SetInventory( ([
          S_NPC + "runner.c" : 1,
              ]) );          
  SetSmell( ([
    "default" :
      "There is a musty odor in the air.",
    
    ]) );
  SetListen( ([
    "default" :
      "The area is strangely quiet.",
          ]) );
    SetExits( ([
    
    "south" : S_ROOM + "r7.c",
    
    ]) );
}
