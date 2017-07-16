#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("guard room");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with a slight amount of artificial"
    " modification.  There are a few brown rags hanging here,"
    " serving as crude curtains. There are strange brownish stains"
    " covering the floor here.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.  In various, random "
      "places, large gouges have been cut out of the wall for no apparent "
      "reason. ",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"stain","stains","brownish stains","brownish stain"}) :
      "The stains appear to be dried blood.  Quite a slaughter must have "
      "taken place here.",  
    ({"curtains","rags","crude curtains","brown rags","rag","curtain"}) :
      "These nearly rotted scraps of fabric are musty and filled "
      "with holes. Strange runes appear to have been painted on them "
      "in blood." 
               
    ]) );  
  SetInventory( ([
          S_NPC + "s_vermin.c" : 1,
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
    
    "southwest" : S_ROOM + "r11.c",
    "northeast" : S_ROOM + "r6.c",
    ]) );
}
