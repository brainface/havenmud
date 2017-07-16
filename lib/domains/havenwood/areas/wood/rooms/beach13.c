/* This is the thirteenth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../beach.h"

inherit LIB_FISHING;
static void create() {

	::create();
	SetSmell( ([ "default" : "The strong smell of salt is strong this "
				 "close to the water." ]) );
	SetLong( "The water here in the shallow part of the sea is cold, and "
		 "the sand underneath is soft.  The deep blue waters ahead "
		 "look dark and cold. Here, the seagulls fly overhead, "
		 "landing on the surface of the water occasionally." );
	SetListen( ([ "default" : "While standing in the shallow water, "
				  "the splashing of fish can be heard." ]) );
	SetInventory( ([
		BEACH_NPC + "fish" : 2,
		BEACH_NPC + "watersnake" : 1,
		]) );
	SetShort("the shallow waters of the sea" );
	SetItems( ([
		"salt" : "The salt can not be seen in this water.",
		( { "water", "sea", "waters" } ) : "The dark water of the "
						   "eastern sea is rough and "
						   "covered in waves.",
		"sand" : "The smooth sand can be seen along the shore.",
		"shore": "This is where the sand and the water meet.",
		( { "seagulls", "seagull" } ) : "These birds fly high above.",
		( { "fish", "fishes" } ) : "The multi-colored fish swim in "
					   "the shallow water.",
		( { "bird", "birds" } ) : "These seagulls fly high above the "
					  "sea.",
		"waves": "These large white-capped waves cover the sea."
		]) );
	SetClimate("temperate");
	SetExits( ([
		"south"     : BEACH_ROOM "beach12",
		"northwest" : BEACH_ROOM "beach18",
		"north"     : BEACH_ROOM "beach14",
		"east"      : INNERSEA_VIRTUAL "ocean/12,36",
		]) );
	SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
}
