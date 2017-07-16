#include <lib.h>
#include <std.h>
#include "../ice.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);    
    SetShort("inside an ice-fishing shack");
    SetLong(
	"A rude shack, centered over a small, circular hole in the "
	"ice.  It is a simple, wooden, roofed box, and apparently "
	"quite old. Built of old planking, and apparently far "
	"beyond its best times, its only function seems to be that "
	"it keeps the worst of the arctic winds off of its single "
	"inhabitant. It does little to hold back the pervasive "
	"chill. "
	  );
    SetItems( ([({"ice-fishing shack","shack", "fishing shack", }) : 
	"The hut is built of splintery planks. It contains nothing "
	"much to look at. " ,
	({"contents", }) :
	"There is nothing interesting here to look at. ",
	({"hole", "circular hole", "small circular hole",
	"hole in the ice", "ice hole", }) :
	"There is a small opening cut in the lake ice, for fishing. "
	"the water is covered with a layer of frozen slush. ",
	({"wood", "planking", "old planking", "wood planking", }) :
	"The boards are splintered and poorly joined.",
      ]) );
    SetListen( (["default" : "The wind howls forlornly over "
	"the ice outside."]));
    SetSmell(  (["default" : "The air here is crisp and cold."]));
    SetExits( ([ "out" : "campsite"]));
    SetInventory(([
	STD_OBJ + "light/torch": 1, 
     	ICE_DIR + "/npc/icefishman": 1]) );
}

/** Approved by Laoise at Fri Jul  9 20:21:31 2004. **/
