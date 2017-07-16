#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("barracks");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with a slight amount of artificial"
    " modification.  There are a few crimson rags hanging here,"
    " serving as crude curtains.  There is a primitive looking bunk"
    " adorned with dingy bedclothes along one of the walls.");
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
     ({"bunk","bedclothes","primitive looking bunk"}) : 
      "The uncomfortable looking bunk is made from a piece of gnarled "
      "wood chained to the wall.  The bedclothes atop it are absolutely " 
      "filthy and probably swarming with lice."          
    ]) );  
  SetInventory( ([
          S_NPC + "s_vermin.c" : 1,
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
    
    "southwest" : S_ROOM + "r6.c",
    
    ]) );
}
