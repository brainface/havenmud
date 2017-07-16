/* This is a basic seagull coded by Lynna on January 20, 1998
*/
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("seagull");
	SetShort("a dirty, gray seagull");
	SetId( ({"seagull", "gull"}) );
	SetAdjectives( ({"dirty", "gray"}) );
	SetInventory( ([
		]) );
	SetCorpseItems( ([
		BEACH_OBJ + "feather" : 2,
		]) );
	SetLong("The dirty, gray seagull flies above the edge of the "
		"water, squawking and bothering those that walk "
		"below it.");
	SetRace("bird");
	SetClass("animal");
	SetLevel(3);
	
	SetGender("female");
	SetAction(5, ({
	"!emote squawks.", "!emote lands on the water." }) );
	}
