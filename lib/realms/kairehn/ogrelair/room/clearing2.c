/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(30);
  SetShort("before a cave opening");
  SetExits( ([  "east" : LAIR_ROOMS + "clearing1", ]) );
  SetSmell( ([ "default" : "There is a distinct smell of rotting flesh here.", ]) );
  SetListen( ([ "default" : "The surrounding trees rustle in the wind." ]) );
  SetLong("The hill dips slightly here before an opening in a rockface, forming "
          "a cave. There seems to be a flicker of light in the opening, "
          "suggesting that it may not be uninhabited. Snow-covered trees "
          "surround the area, though the clearing extends to the east.");  
  SetItems( ([ 
    "hill" : "The hill dips slightly here before a cave opening.",                
    "trees" : "The snow-covered trees rustle in the wind.",
    "rockface" : "There is a cave opening in the jagged rockface.",
    ({ "opening", "cave"}) : "There is a flicker of light in the cave.",
    "clearing" : "The clearing lies to the west.",
  ]) );
  SetItemAdjectives( ([ 
    "hill" : "small",
    "trees" : "snow-covered", 
  ]) );  
  SetEnters( ([ "cave" : LAIR_ROOMS "cave1",
  ]) );
}
