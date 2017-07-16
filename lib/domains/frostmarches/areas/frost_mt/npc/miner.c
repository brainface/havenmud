//
// A dwarven miner
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_NPC;

static void create() {
	npc::create();
	SetKeyName("miner");
	SetId( ({ "miner" }) );
	SetAdjectives( ({ "dwarf", "dwarven" }) );
	SetShort("a dwarven miner");
	SetLong("This dwarven miner seems to want to be alone to do "
		"his job of mining and getting drunk. He looks very "
		"unpleased with everything around him as he constantly "
		"has a frown on his face.");
	SetRace("dwarf");
	SetGender("male");
	SetClass("fighter");
	SetLevel(6);
	SetAction(3, ({ "!emote picks at the wall with his axe.",
			 "!emote drinks some of his beer.",
			 "!burp" }) );
	SetCurrency("senones",random(6)+70);
	SetInventory( ([ OBJ "/beer" : 1,
			 OBJ "/pick-axe" : "wield axe" ]) );

}


/* Approved by Duuktsaryth on Wed Nov 26 00:14:03 1997. */