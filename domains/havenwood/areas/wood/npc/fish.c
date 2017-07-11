/* This is a fish coded by Lynna on January 20, 1998
 Edited by Syra on 7/18/98 to reflect the fact that 'fishes' isn't correct. */
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("fish");
	SetShort("a rainbow fish");
	SetId( ({"fish"}) );
	SetAdjectives( ({"rainbow"}) );
	SetLong("This colorful fish swims smoothly through"
		" the depths of the water, avoiding the "
		"other water animals within.");
	SetRace("fish");
	SetClass("animal");
	SetLevel(1);
	
	SetGender("female");
	SetAction(4, ({
        "The fish dart beneath the water.",
        "The fish jump.",
	}) );
	}
