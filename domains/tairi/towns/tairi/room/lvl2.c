#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("The Taisoka Temple's second floor");
  SetExits( ([
    "down" : "temple",
    "up"   : "lvl3",
          ]) );
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong("This level seems larger and more open. The ceiling hangs "
          "low. This area is obviously reserved as a healing area. "
          "The floor is tiled from wall to wall, and in the center of the "
          "room staircase leads up to the third floor.  A set of large "
          "cabinets stand on the sides of the staircases. The air contains "
          "an almost tangible sensation of relaxation.");
  SetItems( ([
    ({ "level" }) :
    	 (: GetLong :),
    ({ "ceiling" }) :
    	 "The ceiling hangs low with the staircase in the center.",
    ({ "floor" }) : 
    	 "The floor is covered with hexagon tiles.",
    ({ "tile", "tiles", }) : 
    	 "The tiles are painted with pictures of heros and dragons.",
    ({ "cabinet", "cabinets" , "set" }) : 
    	 "These cabinets are made of crystal and contains all sorts of potions "
    	 "and containers.",   
    ({ "staircase", "staircases" }) :
    	 "The center of the room has staircases going up and down.",              
    ]) );
  SetItemAdjectives( ([
    "cabinet" : ({ "crystal", "large" }),
    ]) );
  SetInventory( ([
        TAI_RI_NPC "healer" : 1,
    ]) );
  SetSmell( ([
    "default" : "The scent of medicine hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "Quite whispers fade in and out of hearing range.",
    ]) );
}
