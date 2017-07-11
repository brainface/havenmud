#include <lib.h>
#include "../ice.h" 
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);    
    SetShort("inside a snug hide-covered tent");
    SetLong(
	"This tent is well-constructed, with double-thick walls "
	"and a warm groundcloth to keep out the cold. For the most "
	"part, it is neat and tidy. A few unfinished fishing lures "
	"lie atop an upturned, empty crate, and a bedroll piled "
	"with furs is spread on the ground along one wall. This "
	"appears to be the home of someone who enjoys solitude and "
	"thinking long thoughts. " 
	);
    SetItems( ([({"tent","snug tent", "hide", "snug hide-covered "
	"tent", "snug hide tent", "hides", }) : 
	"The tent is cleverly made to keep out drafts and "
	"condensation, with double-layered hide walls attached to a "
        "thick groundcloth." ,
	({"lures", "lure", "fishing lure", "unfinished lures", 
        "unfinished fishing lures", "fishing lures", "unfinished "
	"fishing lures", "unfinished lure", }) :
	"A jumble of wood, feathers, and strings are scattered over "
	"the top of an upturned wooden box. ",
	({"wood", "box", "crate", "upturned crate", "upturned box", 
	"wooden box", "wooden crate", "upturned wooden box",
	"upturned wooden crate", }) :
	"This is simply an old, empty wooden box, which the owner is "
	"apparently using as a worktable.",
	({"bedroll", "bed", "roll", }) :
	"The fisherman has made himself a comfortable bed on the "
	"floor against one wall of the tent. ",
	({"furs", "fur", }) :
	"A heap of grey furs lies on the sleeping mat... Are those "
	"furs MOVING?.",
	({"ground", "floor", "groundcloth", }) :
	"A thick, tough hide covers the floor. It is sewn to the "
	"walls of the tent all around, keeping out drafts.",
	({"wall", "tent wall", "groundcloth", "ground", "ground cloth",
	 }) :
	"Two layers of dressed animal hides form the walls of the "
	"tent. They are sewn all around to a strong groundcloth "
	"made of buffalo skin.",
	]) );
    SetListen( (["default" : "The howl of the wind is muted here. "
	]));
    SetSmell(  (["default" : "A musky scent fills the air."]));
    SetExits( ([ "out" : "campsite"]));
    SetInventory(([ ICE_DIR + "/npc/lynx": 1]) );
}


/** Approved by Laoise at Fri Jul  9 20:21:35 2004. **/