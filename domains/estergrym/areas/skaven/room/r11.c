#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("beast lair");
  SetLong("This large cavern appears to be mostly a natural"
    " formation with a subtle amount of artificial"
    " modification.  There are a few brown rags hanging here,"
    " serving as crude curtains.  Along the wall at several"
    " spots are hardpoints for attatching heavy iron chains.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.  In various, random "
      "places, large gouges have been cut out of the wall for no apparent "
      "reason. ",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"curtains","rags","crude curtains","brown rags","rag","curtain"}) :
      "These nearly rotted scraps of fabric are musty and filled "
      "with holes. Strange runes appear to have been painted on them "
      "in blood.", 
    ({"chains","hardpoints","heavy chains","heavy chain","hardpoint","spot","spots","chain"}) :
      "The hardpoints are heavy iron plates bolted to the wall that "         
      "incorporate a thick loop for securing the extremely large iron "
      "chains that are present."  
    ]) );  
  SetInventory( ([
          S_NPC + "ogre.c" : 1,
              ]) );          
  SetSmell( ([
    "default" :
      "There is a sweaty odor in the air.",
    
    ]) );
  SetListen( ([
    "default" :
      "The area is strangely quiet.",
          ]) );
    SetExits( ([
        
    "northeast" : S_ROOM + "r10.c",
    ]) );
}
