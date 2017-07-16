#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("cage room");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with only a slight amount of artificial"
    " modification.  There is a large cage in this room"
    " constructed of a sickly looking wood.  A small wire runs" 
    " from the open cage door to a tiny hole in the wall."    
    " The floor is strewn with debris and the"
    " occasional bone can be seen.  The area is littered with"
    " rodent feces.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor", "formation","modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ({"cage","large cage"}) :
      "The cage is small and squat, and could probably hold a dozen hungry rats.",
    ({"bones","debris","bone"}) :
      "The remains of some unfortunate life forms lie scattered over "
      "the floor.",
     ({"remains","remain"}) :
      "The remains appear to have been human at one time.", 
     ({"feces","rodent feces"}) :
      "It looks like a lot of rodents have been using this cavern.",
     ({"hole","tiny hole"}) :
      "A tiny hole in the wall barely large enough to fit the wire.",     
     ({"wire","small wire"}) :
      "a slender wire runs from the cage door to the small hole." 
    ]) );  
  SetInventory( ([
          S_NPC + "rat.c" : 3,
           ]) );          
  SetSmell( ([
    "default" :
      "The fetid odor of decay and defecation fills the air.",
    ({"bones" , "debris"}) :
      "The scent of rot and mildew is obvious.",
    ]) );
  SetListen( ([
    "default" :
      "There is a slight noise in the distance that sounds like a "
      "ringing bell.",
    ]) );
    SetExits( ([
    "east" : S_ROOM + "r2.c"
        ]) );
}
