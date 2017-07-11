//
// A caribou
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>

inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("wild camel");
	SetId( ({ "camel" }) );
	SetAdjectives( ({ "wild" }) );
	SetShort("a wild desert camel");
	SetLong(
	  "This large camel is wandering through the desert "
		"looking for scraps of food to eat. He has large humps "
		"on his back, looking bored and unimpressed."
		);
	SetRace("horse", "camel");
	SetGender("male");
	SetClass("animal");
	SetLevel(15);
	
}


/* Approved by Duuktsaryth on Wed Nov 26 00:15:07 1997. */
