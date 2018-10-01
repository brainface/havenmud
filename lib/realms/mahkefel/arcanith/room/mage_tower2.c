/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("At the Shattered Pinnacle of the Fallen Tower");
  SetClimate("arctic");
 
  SetLong("The pinnacle was evidently roofed in a flimsier material, "
    "as you stand on a pile of green painted shingles as the arctic "
    "winds whip through the gaping holes they've left. Amongst the "
    "shingles, a wide circular hole perilously fills what's currently "
    "the floor. THe ruins of the lower stories lie to the south.");

  SetItems( ([    
      
  ]) );

  SetExits( ([
    "west" : ROOM "/mage_tower1",    
  ]) );
 
  SetSmell( ([
    "default"  : "The wind robs all scent from the room.",
  ]) );

  SetTouch( ([
    "default" : "Whatever fading enchantment keeps the rest of the city "
      "warm has utterly failed here."
  ]) );
  
  SetListen( ([
    "default"  : "Underneath the howling of the wind, you think you hear "
       "a distant ticking noise.",
  ]) );

  SetInventory( ([
    //NPC "/koboldm"  : 2
  ]) );

}

