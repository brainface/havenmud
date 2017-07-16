#include <lib.h>
#include "path.h"

inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("mountain wolf");
	SetShort("a mountain wolf");
	SetId( ({ "wolf" }) );
	SetAdjectives( ({ "mountain" }) );
	SetRace("dog");
	SetClass("animal");
	SetLevel(3);
	SetLong("This regal animal has a pelt of grey covering a thin yet "
		"strong form. His eyes show the intelligence of a racial "
		"history which causes the sentient races to fear his race "
		"with universal hatred.");
	SetGender("male");
}


/* Approved by Duuktsaryth on Wed Nov 26 00:14:21 1997. */