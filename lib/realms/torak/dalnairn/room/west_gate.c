//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <domains.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

int PreventLeaveDalnairn();

static void create() {
  ::create();
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("at the mouth of a tunnel");
  SetDayLong(
    "A tunnel has been mined out of the mountain ridge "
    "allowing travel to the east. "
    "To the west a dense tropical forest grows blocking "
    "further view. "
    "It glows green with warmth and sunlight. "
    "A worn path through the tunnel splinters here into "
    "three going westwardly into the forest. ",
  );
  SetNightLong(
    "A tunnel has been mined out of the mountain ridge "
    "allowing travel to the east. "
    "To the west a dense tropical forest grows blocking "
    "further view. "
    "It is bathed in glowing moonlight. "
    "A worn path through the tunnel splinters here into "
    "three going westwardly into the forest. ",
  );
  SetItems( ([
    ({ "forest" }) :
       "The tropical forest grows right up to the ridge. ",
    ({ "light", "sunlight", "moonlight" }) :
       "The forest glows in the light.",
    ({ "tunnel", "rock", "wall", "walls" }) :
       "This well hewn tunnel was mined through the rock of the ridge. "
       "its walls are smooth to the touch and without flaw.",
    ({ "path" }) :
       "The worn path through the tunnel splits here in three directions, "
       "each running into the forest to the west.",	
    ({ "ridge" }) :  
       "The forest grows to the edge of the mountain ridge. "
       "The top of the ridge can not be seen from here.",
  ]) );
  SetItemAdjectives( ([
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
    "northwest" : DAL_ROOM "3,1.c",
    "west" : DAL_ROOM "3,0.c",
    "southwest" : DAL_ROOM "3,-1.c",
  ]) ); 
  AddExit(
    "east", DAL_ROOM "tunnel.c", 
            (: PreventLeaveDalnairn :) 
  );
  SetEnters( ([
  ]) );
}

int PreventLeaveDalnairn() {
    if (this_player()->id("dalnairn_wander")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
    if (this_player()->GetProperty("dalnoleave")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
  return 1;
}
