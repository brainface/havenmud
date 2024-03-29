#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;
#define ROAD "/domains/estergrym/virtual/grymxoria_road/"

static void create()  {

  room::create();

  SetShort("prison camp gate");
  SetExits(  ([ "north" : P_ROOM + "pc8",
	"south" : ROAD + "39,0",
	])  );
  SetAmbientLight(20);
  SetClimate("underground");
  SetLong("This is the entrance to what the Nosferatu laughingly "
	  "call the Elven Recreational Workout Facility.  To the "
	  "north there lies a large area where many filthy elves are "
	  "turning large rocks into small rocks.  The way south leads "
	  "to the road and Grymxoria.");
  SetInventory(  ([P_NPC "guard" : 2 ])  );
  SetSmell(  ([ 
	"default" : "The smells of the city come faintly from the south.",
	"rock" : "Mmmmmm...Smells like rock",
	])  );
  SetItems( ([
	({ "entrance", "gate" }) : "A large stone gate with foot thick stone "
		"doors set in the side of the mountain",
	({ "rocks", "elves", "area", "rock", "elf" }) :
		"The guards make it impossible to see.  ",
	({ "grymxoria", "road" }) : "The city rises to the south.",
	])  );
  SetListen(  ([
	"default" : "The sound of metal clanging on rock punctuated by the "
		    "occasional cry of pain, wells from the camp.  ",
	])  );
}
