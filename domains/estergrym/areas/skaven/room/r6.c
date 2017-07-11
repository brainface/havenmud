#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("meeting room");
  SetLong("This huge cavern appears to be mostly a natural"
    " formation with a fair amount of artificial"
    " modification.  This part of cave appears inhabited."
    " There are crude tables and chairs here and"
    " the remains of a firepit.  The walls are covered with"
    " crudely painted runes.");
  SetItems( ([
    ({"cave","cavern"}) : (:GetLong:),
    ({"wall","walls", "floor","formation", "modification","natural formation","artificial modification"}) :
      "The walls are rough and natural, but the openings appear "
      "to have been chiseled out and enlarged. Black runes adorn"
      "the walls.",
    ({"openings","opening"}) :
      "The openings are barely large enough for a man to fit through.",
    ({"tables","chairs","table","chair"}) :
      "The tables and chair are roughly fashioned from a peculiar "
      "type of wood and look suited to something slighly smaller than. "
      "man-sized. ",
     ({"runes","black runes","painted runes","rune"}) :
      "These unusual runes were painted very roughly with a thick "
      "black substance.", 
     ({"firepit","pit"}) :
      "The blackened ashes still have a few embers within." 
         
    ]) );  
  SetInventory( ([
          S_NPC + "dslave.c" : 2,
          S_NPC + "s_vermin.c" : 2,
           ]) );          
  SetSmell( ([
    "default" :
      "There is a somewhat smoky smell in the air.",
    
    ]) );
  SetListen( ([
    "default" :
      "The area is strangely quiet.",
          ]) );
    SetExits( ([
    
    "northeast" : S_ROOM + "r9.c",
    "southeast" : S_ROOM + "r5.c",
    "north" : S_ROOM + "r7.c",
    "southwest" : S_ROOM + "r10.c",
    ]) );
}
