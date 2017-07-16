// Title: Durgoroth Town
// File: agburnar.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Agburnar, fighter leader of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "rescueme.h"

void DoAction();
void Splat( object who, object target );

static void create() {
	leader::create();
	SetKeyName("agburnar");
	SetRace("nosferatu");
	SetClass("fighter");
	SetLevel(40);
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetReligion("Saahagoth");
	SetMorality(-1000);
	SetShort("Agburnar, Captain of the Durgoroth Guard");
	SetId( ({ "agburnar","captain of the guard","captain" }) );
	SetLong("Agburnar is a giant muscular Nosferatu. He has many scars "
					"and a patch over his left eye. He glares at you out of his good eye. "
					"Agburnar is definitely not one to mess with.");
	SetInventory( ([
		D_OBJ + "/blood_sword"    : "wield blood sword in left hand",
		D_OBJ + "/katana"         : "wield katana in right hand",
		D_OBJ + "/nosf_armour"    : "wear armour",
		D_OBJ + "/crusade_shield" : "wear shield on left arm",
		]) );
	SetPlayerTitles( ([
		"newbie" : "the Apprentice Guardsman of Durgoroth",
		"mortal" : "the Guardsman of Durgoroth",
		"hm"     : "the Captain of the Durgoroth Guard",
		"legend" : "the General of the Durgoroth Guard",
		"avatar" : "the Legendary High General of the Durgoroth Guard",
		]) );
	SetCurrency("crystals", 100 + random(201));
	SetCombatAction( 35, ({
		(: DoAction :),
		"!disarm",
		"!disorient",
		}) );
	SetFreeEquip((["/std/weapon/slash/longsword":1]));
	}

void DoAction() {
	if(!random(3))
		leaderToMe();
	else if(random(2))
		Splat(this_object(), this_object()->GetCurrentEnemy());
	else {
		object target = GetCurrentEnemy();
		this_object()->eventForce("slice "+target->GetKeyName()+
			" with katana");
		}
	}

void Splat( object who, object target ) {
	message("splat", "Agburnar screams with "
		"%^BOLD%^RED%^BLOODLUST%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
