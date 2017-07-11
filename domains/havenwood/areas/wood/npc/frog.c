/* This is a frog coded by Lynna on January 20, 1998
*/
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("frog");
	SetShort("a jumpy, green frog");
	SetId( ({"frog"}) );
	SetAdjectives( ({"green", "jumpy"}) );
	SetLong("This green frog jumps from lilypad to lilypad "
		"through the water hardly disturbing "
		"the others that live here.");
	SetRace("amphibian");
	
	SetClass("animal");
	SetLevel(1);
	SetGender("male");
	SetAction(5, ({
	"!emote jumps.", "!emote ribbits.", "!emote croaks."}) );
	}
