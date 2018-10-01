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

static void create() {
  ::create();
  SetClimate("underground");
  SetShort("inside a tunnel");
  SetLong(
    "A tunnel has been mined out of the mountain ridge. "
    "The rock walls of the tunnel are smooth and well hewn "
    "To the west a dense tropical forest grows blocking "
    "further view while to the east the path through "
    "the tunnel connects to Averath Road. "
  );
  SetItems( ([ 
    ({ "road" }) :
       "The path through the tunnel connects to the Averath Road "
       "to the east.",
    ({ "forest" }) :
       "The tropical forest grows right up to the ridge to the west. ",
    ({ "light", "sunlight", "moonlight" }) :
       "The forest glows in the light.",
    ({ "tunnel", "rock", "wall", "walls" }) :
       "This well hewn tunnel was mined through the rock of the ridge. "
       "its walls are smooth to the touch and without flaw.",
    ({ "path" }) :
       "The woirn path through the tunnel connects Averath Road to the forest.",	
    ({ "ridge" }) :  
       "The forest grows to the edge of the mountain ridge. "
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "averath" }),
    "forest" : ({ "dense", "tropical" }),
    "tunnel" : ({ "well", "hewn", "rocky", "smooth" }),
    "path" : ({ "trampled" }),
    "ridge" : ({ "mountain" }),
  ]) );  
  SetInventory( ([
  ]) );
  SetListen( ([
    "default" : "Sounds of outside life echo falsely across the tunnel.",
  ]) );
  SetSmell( ([
    "default" : "The air is damp.",
  ]) );
  SetExits( ([
    "east" : DAL_ROOM "east_gate.c",
    "west" : DAL_ROOM "west_gate.c",
  ]) ); 
  SetEnters( ([
  ]) );
}

