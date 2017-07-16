// Title : Durgoroth Town
// File: innkeeper.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	
//
// Revision History: 
//

#include <lib.h>
#include "../durgoroth.h"
#include "rescueme.h"
inherit LIB_BARKEEP;

static void create() {
	barkeep::create();
	SetKeyName("horgan");
	SetId( ({ "innkeeper" }) );
	SetShort("Horgan, innkeeper of the Dark Sun Inn");
	SetLong("Horgan is a slightly fat, balding, middle aged man. "
				  "He has run this Inn for most of his life, and is a shrewd "
					"buisinessman. He will sell you a meal, or a place to stay "
					"if you have enough coins.");
	SetRace("human");
	SetClass("fighter");
	SetSkill("bargaining",4,0);
	SetLevel(20);
	SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
	SetMorality(-40);
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		]) );
	SetCurrency("crystals", 25 + random(26));
	SetCombatAction( 30, (: summonGuard, this_player() :));
	SetMenuItems( ([
		"mutton" : D_OBJ + "/mutton",
		"porridge" : D_OBJ + "/porridge",
		]) );
	SetLocalCurrency("crystals");
	}
