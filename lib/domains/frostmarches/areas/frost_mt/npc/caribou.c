//
// A caribou
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("artic caribou");
	SetId( ({ "caribou" }) );
	SetAdjectives( ({ "arctic" }) );
	SetShort("an arctic caribou");
	SetLong("This large caribou is wandering through the mountain "
		"looking for scraps of food to eat. He has large antlers "
		"on his head, looking ready for any duel to the death.");
	SetRace("deer");
	SetGender("male");
	SetClass("animal");
	SetLevel(4);
	
}


/* Approved by Duuktsaryth on Wed Nov 26 00:15:07 1997. */