/* This is a turtle coded by Lynna on January 20, 1998
*/
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("turtle");
	SetShort("a large, green turtle");
	SetId( ({"turtle"}) );
	SetAdjectives( ({"green", "slow", "large"}) );
	SetLong("This large, green turtle slowly walks the shores"
		" of the beach, hoping not to fall asleep on his "
		"journey.");
	SetRace("tortoise");
	SetClass("animal");
	SetLevel(1);
	SetGender("male");
	SetAction(3, ({
	"!emote looks around.", "!emote pauses in his walking."}) );
	}
