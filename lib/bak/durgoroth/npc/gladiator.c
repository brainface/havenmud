// Title : Durgoroth Town
// File: guard.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	A standard guard of Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_SENTIENT;
#include "../durgoroth.h"
#include "guardian.h"

void Splat( object who, object target );

static void create() {
	sentient::create();
	SetKeyName("gladiator");
	SetId( ({ "" }) );
	SetShort("an arena Gladiator");
	SetLong("This large, muscled, and scarred Gorithim Gladiator "
					"has seen years of constant combat. And must have won most "
					"of his fights, or he wouldn't be standing here now. He "
					"looks very experienced, and ready to fight at the drop "
					"of a coin.");
	SetRace("human");
	SetClass("fighter");
	SetSkill("melee combat",1,1);
	SetLevel(20 + random(25));
	SetGender("male");
	SetMorality(-50);
	SetCurrency("crystals", 50 + random(51));
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		D_OBJ + "/chainmail" : "wear chainmail",
		D_OBJ + "/fur_cloak" : "wear cloak",
		D_OBJ + "/axe" : "wield axe in right hand",
		D_OBJ + "/brass_knuckles" : "wield knuckles in left hand",
		]) );
	SetAction( 10, "The Gladiator brags about his victories.");
	SetCombatAction( 15, (: Splat, this_object(),
		this_object()->GetCurrentEnemy() :));
	SetFriends( friends );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	}

void Splat( object who, object target ) {
	message("splat", "The Gladiator screams with "
		"%^BOLD%^RED%^bloodlust%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
