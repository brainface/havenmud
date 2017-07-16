// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(40);
  SetShort("the Drunken Rat Tavern");
  SetLong(
	 "This medium sized chamber, which the owner of this tavern calls the "
	 "Drunken Rat, has a large fireplace along the east wall. The "
	 "fireplace casts a few shadows in the corners of the tavern while "
	 "also keeping the patron's warm. A few round tables sit scattered "
	 "around the room, with six small wooden stools tucked under the "
	 "table when not being used. Along the south wall is a long wooden "
	 "countertop that is used as the bar. Wooden shelves, behind the "
	 "bar, are stocked with pewter mugs, waiting for the next customer. "
	 "A door in the middle of the west wall, leads back to the "
	 "stone tiled road."
	 );
  SetItems( ([
	   ({"room","tavern","drunken rat","rat","chamber"}) : (: GetLong :),
	   ({"fireplace","east wall"}) :
	   "In the middle of the east wall, a large firewall warms the "
	   "tavern while cooking the patron's food and lights up the room "
	   "of the tavern casting shadows in the corners.",
	   ({"shadows","flame"}) :
	   "The shadows dance around the room in rhythm with the flame "
	   "within the fireplace.",
	   ({"tables","table"}) :
	   "A few round wooden tables are scattered throughout the tavern "
	   "near the fireplace and in the northeast corner of the room.",
     ({"stools","stool"}) :
	   "There are six small wooden stools sitting around the table "
     "waiting to be used.", 
     ({"south wall","countertop","bar"}) :
	   "The long wooden countertop that sits near the south wall acts "
	   "as the tavern's bar.",
	   ({"shelves","shelf"}) :
	   "Wooden shelves run the length of the south wall. On the shelves "
	   "are pewter mugs waiting to be filled and be served to the patrons "
	   "of the Drunken Rat.",
	   ({"mugs","mug"}) :
	   "The pewter mugs sit on the wooden shelves waiting to be used in "
	   "quenching a patron's thirst.",
	   ({"door","doorway","west wall","road"}) :
	   "Across the from the fireplace a doorway is in the middle of the "
	   "west wall which leads back onto the stone tiled road.",
     ]) );
  SetItemAdjectives( ([
	   "room"		  : ({"medium","sized"}),
	   "rat"		  : ({"drunken"}),
	   "fireplace"  : ({"large"}),
	   "tables"     : ({"few","scattered","wooden","round"}),
	   "stools"     : ({"six","small","wooden"}),
	   "countertop" : ({"long","wooden"}),
	   "bar"        : ({"tavern's"}),
	   "shelves"    : ({"wooden"}),
	   "mugs"       : ({"pewter"}),
     "road"       : ({"stone","tiled"}),
     ]) );
  SetListen( ([
     "default" : 
     "The clattering of drunken souls can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of ale fills the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "barkeep"		    : 1,
	   V_NPC + "drunken_watchman" : 2,
	   V_NPC + "citizen"          : 1,
	   V_NPC + "rogue_trainer"    : 1,
     ]) );
  SetExits( ([
     "out"   : V_ROOM + "main_road/main1",
     ]) );
}

