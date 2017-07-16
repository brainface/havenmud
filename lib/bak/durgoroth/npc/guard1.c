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

void DoAction();
void Splat( object who, object target );

static void create() {
	sentient::create();
	if(!(random(3))) {
	SetId( ({ "burly nosferatu","burly guard","durgoroth guard",
		"nosferatu","guard" }) );
	SetShort("a burly nosferatu guard");
	SetLong("The massive, battle hardened Nosferatu soldier "
		"is charged with the protection of the fortress and the "
		"citizens of the town within. He seems to be very well "
		"armed, and ready to destroy any invaders or criminals.");
	SetRace("nosferatu");
  SetTown("Durgoroth");
	SetClass("cavalier");
	SetReligion("Saahagoth");
	SetMorality(-200);
	SetInventory( ([
		D_OBJ + "/blood_sword" : "wield sword in right hand",
		D_OBJ + "/nosf_armour" : "wear armour",
		D_OBJ + "/wall_shield" : "wear shield on left arm",
		]) );
		}
	else {
	SetId( ({ "massive Gorithim guard", "massive human",
		"massive gorithim","durgoroth guard","massive guard",
		"gorithim","human","guard" }) );
	SetShort("a massive Gorithim guard");
	SetLong("The huge, burly, human guardsman is assigned the task "
		"of protecting the fortress and the inhabitants of the town. "
		"His face is weatherworn and scarred, and he looks ready "
		"to do battle to anyone at any time.");
	SetRace("human");
	SetClass("fighter");
	SetSkill("melee combat",1,1);
	SetMorality(-50);
	SetInventory( ([
		D_OBJ + "/chainmail" : "wear chainmail",
		D_OBJ + "/fur_cloak" : "wear cloak",
		D_OBJ + "/axe" : "wield axe in right hand",
		D_OBJ + "/brass_knuckles" : "wield knuckles in left hand",
		]) );
		RemoveLanguage("Enlan");
		SetLanguage("Blaodric", 100, 1);
		}
	SetKeyName("durgoroth guard");
	SetLevel(20 + random(16));
	SetGender("male");
	SetProperty("durgorothNPC", 1);
	SetCurrency("crystals", 50 + random(51));
        SetAction( 10, "The Durgoroth Guard hefts his weapon impatiently.");
	SetCombatAction(25, (: DoAction :) );
	SetFriends( friends );
	SetWander( 3 + random(5), ({ "go up","go west","go west","go west",
		"enter tower","go north","go north","go north","go south",
		"go down","go east","go east","go east","go north","go north",
		"go south","go south","go east","go east","go east","go up",
		"go north","go south","go south","enter tower","go west",
		"go west","go west","go west","go down" }), 1 );
	}

void DoAction() {
	if(random(2))
		Splat(this_object(),this_object()->GetCurrentEnemy());
	else {
		if(GetRace() == "nosferatu")
			this_object()->eventForce("slice");
		else {
			object target = GetCurrentEnemy();
			this_object()->eventForce("hack "+target->GetKeyName()+
				" with axe");
			}
		}
	}

void Splat( object who, object target ) {
	message("splat", "The Durgoroth Guard screams with "
		"%^BOLD%^RED%^bloodlust%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
