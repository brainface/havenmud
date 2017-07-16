#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("garbage chamber");
  SetLong("This small cavern appears to be mostly a natural"
    " formation with only a slight amount of artificial"
    " modification.  A disgusting pile of rancid debris and"
    " garbage fills most of this room.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls","formation","modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged.",
    ("floor") : 
      "The uneven floor is scarcely visible beneath the mound of garbage.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"debris","garbage","pile","disgusting pile","rancid debris"}) :
      "This revolting heap consists of bones, rags, rotted meat,  "
      "broken weapons and even more rodent feces.",
     ({"weapons","weapon","broken weapons","broken weapon"}) :
      "The rusted remnants of ancient weapons.", 
     ({"feces","rodent feces"}) :
      "It looks like a lot of rodents have been using this cavern."    
    ]) );  
  SetInventory( ([
          S_NPC + "dslave.c" : 1,
           ]) );          
  SetSmell( ([
    "default" :
      "The smell of rotting garbage is overpowering.",
    
    ]) );
  SetListen( ([
    "default" :
      "The area is strangely quiet.",
          ]) );
    SetExits( ([
    
    "northwest" : S_ROOM + "r6.c",
    "south" : S_ROOM + "r4.c",
    ]) );
}
