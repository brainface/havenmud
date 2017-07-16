// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("at the eastern gate of Averath");
  SetLong(
    "The gate to the east marks the Averath city bounds. The paved road leads "
    "east into the Duchy of Averath, out of the protection of the city guards. "
    "To the west lies the city of Averath itself, a prosperous civilization "
    "ruled over by a Duke. There is a wooden bench to the side of the road "
    "where the guards often sit when not on watch."
  );
  SetItems( ([
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    ({ "city", "Averath" }) : "The city of Averath is a prosperous place. The "
    	"buildings look very well maintained.",
    ({ "gate", "bounds" }) : "The gate to the east marks the city bounds. "
      "Guards usually stand here, ready to defend against invaders and "
      "ward off any criminals.",
    ({ "bench" }) : "This wooden bench provides a place to rest for guards "
    	"who are not on watch.",    
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "paved" }),
    "bench" : ({ "wooden" }),
  ]) );
  SetInventory( ([    
    AVERATH_NPC "swashbuckler" : 1,
  ]) );
  SetListen( ([
     "default" : "The sounds of city life drift in from the west.",
  ]) );
  SetSmell( ([
     "default" : "The city smells very clean, and is clearly well looked "
     	 "after.",
  ]) );  
  SetExits( ([    
    "west" : AVERATH_ROOM "road3",
    //"east" : AVERATH_ROOM "someplace",
  ]) );    
}
