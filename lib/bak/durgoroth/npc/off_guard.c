// Title : Durgoroth Town
// File: off_guard.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	An off duty guard of Durgoroth town
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
	if(!(random(3))) {
	SetId( ({ "off-duty nosferatu","off-duty guard","durgoroth guard",
		"nosferatu","guard","off duty guard" }) );
	SetShort("an off-duty nosferatu guard");
	SetLong("The massive, battle hardened Nosferatu soldier "
					"is charged with the protection of the fortress and the "
					"citizens of the town within. At the moment though, he is "
					"off duty, and looks to be in no mood for intrusions.");
	SetRace("nosferatu");
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
	SetClass("cavalier");
	SetMorality(-300);
	SetInventory( ([
		D_OBJ + "/blood_sword" : "wield sword in right hand",
		]) );
	SetAction( 20, "The nosferatu guard glares impatiently at you.");
	}
	else {
	SetId( ({ "off-duty Gorithim guard", "off-duty human",
		"off-duty gorithim","durgoroth guard","off-duty guard",
		"gorithim","human","guard","off duty guard","off duty" }) );
	SetShort("an off-duty Gorithim guard");
	SetLong("The huge, burly, human guardsman is assigned the task "
					"of protecting the fortress and the inhabitants of the town. "
					"At the moment though he is off-duty and looks to be ready "
					"to enjoy himself.");
	SetRace("human");
	SetClass("fighter");
	SetSkill("melee combat",1,1);
	SetMorality(-150);
	SetInventory( ([
		D_OBJ + "/fur_cloak" : "wear cloak",
		]) );
	SetAction( 10, 
		"The Gorithim guard tells a story of his many adventures."
		);
	SetInventory( ([
		D_OBJ + "/brass_knuckles" : "wield knuckles in left hand",
		]) );
	}
	SetKeyName("durgoroth guard");
	SetLevel(20 + random(16));
	SetGender("male");
	SetProperty("durgorothNPC", 1);
	SetCurrency("crystals", 50 + random(51));
	SetCombatAction( 20, 
		(: Splat, this_object(), this_object()->GetCurrentEnemy() :)
		);
	SetFriends( friends );
	}

void Splat( object who, object target ) {
	message("splat", "The Durgoroth Guard screams with "
		"%^BOLD%^RED%^bloodlust%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
