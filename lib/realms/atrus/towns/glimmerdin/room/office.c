#include <lib.h>
#include <averath.h>
#include "../glim.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetClimate("underground");
  SetProperty("no bump", 1);
	SetAmbientLight(45);
	SetShort("Glimmerdin Clan Hall");
	SetExits( ([
	  "out"  : AVERATH_ISLAND "-8,-3,0",
	  "west" : G_ROOM "post",
	  ]) );
	SetLong("This hall is a stately room carved into the bedrock of the mountain. "
	        "Engraved on every wall are pictures of the history of the clans of "
	        "Glimmerdin. A large desk dominates the north part of the room, with "
	        "an open book which covers nearly the entire surface of the desk. "
	        "The west wall of the office has a door which is clearly marked, "
	        "\"Post\" and can only be Glimmerdin's postal service.");
	SetItems( ([
	  ({ "bedrock" }) :
	    "The stone of the walls and floors is a solid grey in color.",
	  ({ "picture", "pictures" }) :
	    "The pictures detail bits of dwarven history dating back several "
	    "hundred years.",
	  ({ "desk" }) :
	    "This large stone desk seems to dominate the room.",
	  ({ "book" }) : 
	    "This book lists every citizen of Glimmerdin, along with clan affiliation.",
	  ({ "door" }) :
	    "This door is marked \"Post\" and leads into the post office.",
	   ]) );
	 SetItemAdjectives( ([
	   "desk" : ({ "large", "stone", }),
	   "book" : ({ "open", }),
	   "door" : ({ "marked", "post" }),
	   ]) );
	 SetInventory( ([
    G_NPC "banker" : 1,
    G_NPC "sage" : 1,
    G_NPC "trainer" : 1,
	   AVERATH_OBJ "averath_bb" : 1,
           G_NPC "civak" : 1,
           G_NPC "mayor" : 1,
	   ]) );
	 SetSmell( ([
	   "default" : "The hall smells of drying ink and faint dust.",
	   ]) );
	 SetListen( ([
	   "default" : "The room is large, but doesn't seem to echo.",
	   ]) );
}
