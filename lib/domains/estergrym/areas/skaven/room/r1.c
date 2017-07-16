#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("cave entrance");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with only a slight amount of artificial"    
    " modification.  The floor is strewn with debris and the"
    " occasional bone can be seen.  A mild breeze is blowing in"
    " from one of the openings slightly shifting the debris."  );                                         
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"bones","debris","bone"}) :
      "The remains of some unfortunate life forms lie scattered over "
      "the floor.",
     ({"remains","remain"}) :
      "The remains seem to have a tripwire strung through them, which " 
      "has apparently been tripped by an intrusion."    
    ]) );
  SetItemAdjectives( ([
    "walls" : "rough"
        ]) );
  SetSmell( ([
    "default" :
      "The fetid odor of decay fills the air.",
    ({"bones" , "debris"}) :
      "The scent of rot and mildew is obvious.",
    ]) );
  SetListen( ([
    "default" :
      "A faint clicking sound is being slowly drowned out by an "
      "unusual squeaking noise.",
    ]) );
    SetExits( ([
    "north" : S_ROOM + "r2.c",
    "out" : S_ROOM + "r0.c"

    ]) );
}
