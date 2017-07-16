//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("at the mouth of a tunnel");
  SetLong(
    "A tunnel has been mined out of the mountain ridge "
    "allowing travel to the west. "
    "Averath Road becomes a worn path through the tunnel "
    "leading east to a forest on the other side. ",
  );
  SetItems( ([
    ({ "road", "stone", "stones", "blocks" }) :
       "The Averath Road is relatively wide and paved with stone. "
       "It seems ratherly well maintained, though "
       "a few blocks seem to have been knocked out of place.",
    ({ "forest" }) :
       "The tropical forest grows right up to the ridge on the other side "
       "of the tunnel. ",
    ({ "light", "sunlight", "moonlight" }) :
       "The forest glows in the light.",
    ({ "tunnel", "rock", "wall", "walls", "mouth" }) :
       "This well hewn tunnel was mined through the rock of the ridge. "
       "its walls are smooth to the touch and without flaw.",
    ({ "path" }) :
       "A worn path from the forest through the tunnel turns into Averath Road to the east.",	
    ({ "ridge" }) :  
       "The forest grows to the edge of the mountain ridge. "
       "The top of the ridge can not be seen from here.",
  ]) );
  SetItemAdjectives( ([
    "road" : ({ 
      "averath", "paved", "wide", "well", "maintained", "few" 
    }),
    "forest" : ({ "dense", "tropical" }),
    "tunnel" : ({ "well", "hewn", "rocky", "smooth" }),
    "path" : ({ "trampled" }),
    "ridge" : ({ "mountain" }),
  ]) );  
  SetInventory( ([
    DAL_NPC "guard" : 2,
  ]) );
  SetListen( ([
    "default" : "Sounds of the forest echo falsely from the tunnel.",
  ]) );
  SetSmell( ([
    "default" : "The air is damp.",
  ]) );
  SetExits( ([
    "west" : DAL_ROOM "tunnel.c",
    "east" : "/domains/averath/virtual/averathroad/-30,0", 
  ]) ); 
  SetEnters( ([
  ]) );
}
