/* This is a watersnake coded by Lynna on January 20, 1998
*/
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("water snake");
	SetShort("a long skinny water snake");
	SetId( ({ "snake" }) );
	SetAdjectives( ({ "long", "skinny", "water" }) );
	SetLong("This is a long, skinny, water snake that slides "
		"a long the edge of the water hissing and "
		"searching for food.");
	SetRace("snake");
	SetClass("animal");
	SetLevel(5);
	SetGender("male");
	SetAction(5, ({
	"!emote slides along the edge of the water.",
	"!emote hisses loudly."}) );
	}
