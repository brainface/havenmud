#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("feeding pit");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with only a slight amount of artificial"
    " modification.  The floor is strewn with debris and the"
    " occasional bone can be seen.  The area is littered with "
    "rodent feces and the odd skull.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"bones","debris","bone","skull","skulls"}) :
      "The remains of some unfortunate life forms lie scattered over "
      "the floor.",
     ({"remains","remain"}) :
      "The remains appear to have been human at one time.", 
     ({"feces","rodent feces"}) :
      "It looks like a lot of rodents have been using this cavern."    
    ]) );  
  SetInventory( ([
          S_NPC + "rat.c" : 6,
           ]) );          
  SetSmell( ([
    "default" :
      "The fetid odor of decay and defecation fills the air.",
    ({"bones" , "debris"}) :
      "The scent of rot and mildew is obvious.",
    ]) );
  SetListen( ([
    "default" :
      "There is a loud squeaking noise all around.",
          ]) );
    SetExits( ([
    "west" : S_ROOM + "r3.c",
    "northeast" : S_ROOM + "r4.c",
    "south" : S_ROOM + "r1.c",
    ]) );
}
