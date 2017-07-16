// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("at the western gate of Averath");
  SetLong(
    "The gate to the west marks the Averath city bounds. The paved road leads "
    "west into the Duchy of Averath, out of the protection of the city guards, "
    "eventually leading to the city of Dalnairn, a place feared and avoided "
    "by the people of Averath. To the east lies the city of Averath itself, "
    "a prosperous civilization ruled over by the Duke."
  );
  SetItems( ([
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    ({ "city", "Averath" }) : "The city of Averath is a prosperous place. The "
    	"buildings look very well maintained.",
    ({ "gate", "bounds" }) : "The gate to the east marks the city bounds. "
      "Guards usually stand here, ready to defend against invaders and "
      "ward off any criminals.",    
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "paved" }),    
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
     "default" : "The sounds of city life drift in from the east.",
  ]) );
  SetSmell( ([
     "default" : "The city smells very clean, and is clearly well looked "
     	 "after.",
  ]) );  
  SetExits( ([    
    "east" : AVERATH_ROOM "road5",
    //"west" : AVERATH_ROOM "someplace",
  ]) );    
}