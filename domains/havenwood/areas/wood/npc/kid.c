/* This is a child that plays on the beach coded by Lynna on February 11, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("child");
	SetShort("a small child");
	SetInventory( ([
		BEACH_OBJ + "shovel" : "wield shovel"
		]) );
	SetId( ({ "child" }) );
	SetAdjectives( ({ "small" }) );
	SetLong( "This small child spends his time digging in the sand of the "
		"beach.");
	SetRace("gelfling");
	SetClass("merchant");
	SetSkill("blunt combat",1,2);
	SetLevel(2);
	SetGender("male");
	SetAction(5, ({
		"!emote digs in the sand.",
		"!emote looks around."
		}) );
	}
