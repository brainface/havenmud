#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("corridor");
  SetLong("This small corridor appears to be mostly a natural"
    " formation with a fair amount of artificial"
    " modification. Faint footprints are scattered throughout this"
    " corridor. There are a few crimson rags hanging here,"
    " serving as crude curtains.");
  SetItems( ([
    ({"cave","cavern","corridor"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"footprints","faint footprints","footprint"}) :
      "These footprints look like they were made by a large rodent.",  
    ({"curtains","crude curtains","rags","crimson rags","rag","curtain"}) :
      "These nearly rotted scraps of fabric are musty and filled "
      "with holes. "           
    ]) );  
  SetInventory( ([
          S_NPC + "captain.c" : 1,
          S_NPC + "s_vermin.c" : 2,
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
    
    "south" : S_ROOM + "r6.c",
    "north" : S_ROOM + "r8.c",
    ]) );
}
