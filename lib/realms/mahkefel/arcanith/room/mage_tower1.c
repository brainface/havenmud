/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("inside a Fallen Tower");
  SetClimate("indoors");
 
  SetLong("The upper floors of the tower have toppled and collapsed, "
    "creating a sort of man-made tunnel of glimmering emerald and "
    "tortured bits of metal of indescipherable purpose. A huge steel "
    "rod lies twisted and broken along the ground, as well as several "
    "mushrooms of questionable edibility. Bits of greenish light "
    "illuminate paths of egress, the base to the west and what may "
    "be the pinnacle to the east.");

  SetItems( ([    
      
  ]) );

  SetExits( ([
    "east" : ROOM "/mage_tower2",
    "west" : ROOM "/mage_tower0",    
  ]) );
 
  SetSmell( ([
    "default"  : "It smells of mold and rotten meat.",
  ]) );

  SetListen( ([
    "default"  : "Chittering and chirping insects chatter somewhere "
      "just out of sight.",
  ]) );

  SetInventory( ([
    //NPC "/koboldm"  : 2
  ]) );

}

