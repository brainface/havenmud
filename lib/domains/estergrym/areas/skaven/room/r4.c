#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("cramped hallway");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with only a slight amount of artificial"
    " modification.  The natural corridor formed by this room"
    " is very small and cramped.  The floor is jagged and"
    " irregular, making travel difficult.");
  SetItems( ([
    ({"cave","cavern","corridor"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through."       
    ]) );            
  SetSmell( ([
    "default" :
      "The air is very musty and unpleasant.",    
    ]) );
  SetListen( ([
    "default" :
      "There are some faint squeaking noises all around.",
          ]) );
    SetExits( ([
    "southwest" : S_ROOM + "r2.c",
    "north" : S_ROOM + "r5.c",
    
    ]) );
}
