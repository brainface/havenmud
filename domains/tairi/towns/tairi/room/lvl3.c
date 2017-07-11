#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("The Taisoka Temple's third floor");
  SetExits( ([
     "down" : "lvl2",
     ]) );
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong("This is the top level of the temple. All around room, the "
          "town looms across the horizon. The stone floor is completely "
          "barren, and lifeless. The only noticable thing here is "
          "a intricate rug resting in the center of the floor by the "
          "the staircase.");
  SetItems( ([
      ({ "level", "temple", "room", "center" }) :
      	 (: GetLong :),  
      ({ "town", "tairi", "horizon" }) :
      	 "The whole town can be seen from this vantage point.",
      ({ "staircase" }) :
      	 "The wooden staircase heads back down into the lower floors "
      	 "of the Taisoka Temple.",
      ({ "floor" }) : 
      	 "The floor is made up of unmarred stone.",
      ({ "rug" }) : 
      	 "The rug is woven of fine thread and looks quite expensive. ",                
      ]) );
  SetItemAdjectives( ([
      "rug"       : ({ "intricate", "expensive" }),
      "floor"     : ({ "stone" }),
      "staircase" : ({ "wooden" }),
      ]) );
  SetInventory( ([
      TAI_RI_NPC "trainer" : 1,
      ]) );
  SetSmell( ([
      "default" : "The air is tasteless, and without scent.",
      ]) );
  SetListen( ([
      "default" : "Perfect silence is all one can hear.",
      ]) );
}
