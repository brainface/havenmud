/* This is a fisherman for the beach, coded by Lynna on February 11, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("fisherman");
	SetShort("a lone fisherman");
	SetId( ({ "fisherman", "man" }) );
	SetAdjectives( ({ "lone" }) );
	SetLong("This lone fisherman sits near the edge of the water with his "
		"fishing pole and his bait.");
	SetRace("gelfling");
	
	SetGender("male");
	SetClass("merchant");
	SetLevel(2);
	SetInventory( ([
		BEACH_OBJ + "knife" : "wield knife",
		BEACH_OBJ + "fishingpole" : 1,
		]) );
	SetAction(5, ({
		"!emote casts his fishing pole into the water.", 
		"!emote looks around.",
		"!emote baits his hook." }) );
	}
