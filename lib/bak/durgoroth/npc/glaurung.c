// Title: Durgoroth Town
// File: glaurung.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Glaurung, the necromancer leader of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	leader::create();
	SetKeyName("glaurung");
	SetShort("Glaurung Sarkoth, Lord Necromancer of Durgoroth");
	SetId( ({ "glaurung", "glaurung sarkoth", "sarkoth",
		"lord necromancer" }) );
	SetRace("nosferatu"); 
	SetClass("necromancer");
	SetTown("Durgoroth"); 
	SetReligion("Saahagoth");
	SetGender("male");
	SetLevel(50);
	SetProperty("durgorothNPC",1);
	SetMorality(-1500);
	SetLong("Glaurung Sarkoth is a average sized Nosferatu male. "
					"He is dressed in simple robes and leans on a staff. "
					"He has exceptionally long fangs, and seems to have "
					"a certain aura of power.");
	SetInventory( ([
		D_OBJ + "/nosf_staff" : "wield staff",
		]) );
	SetCurrency("crystals", 100 + random(201));
	SetPlayerTitles( ([
		"newbie" : "the Student of the Black Arts",
		"mortal" : "the Practitioner of the Black Arts",
		"hm" 		 : "the Lord of the Undead",
		"legend" : "the Keeper of the Underworld",
		"avatar" : "the Master of the Land of the Walking Dead",
		"deathknight" : "the Bringer of Death",
		]) );
	SetSpellBook( ([
		"distinegrate" : 100,
		"acid rain" : 100,
		"hellfire" : 100,
		"hunger" : 100,
		"cloud kill" : 100,
		"wither" : 100,
		"veil from beyond" : 100,
		"acid splash" : 100,
		"wound" : 100,
		]) );
	SetCombatAction(75, ({
		"!cast wither",
		"!cast hunger",
		"!cast distinegrate",
		"!cast hellfire",
		"!cast cloud kill",
		"!cast veil from beyond",
		"!cast acid rain",
		}) );
	SetFreeEquip( ([
		"/std/weapon/pole/staff":1 
		]) );
  SetTaughtSpheres( ({
  	"conjuring",
  	"conjuring necromancy",
    "conjuring evokation"
    }) );
}
