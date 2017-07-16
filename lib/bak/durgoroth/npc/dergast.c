// Title: Durgoroth Town
// File: dergast.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Dergast, barbarian leader of Durgoroth
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
	SetKeyName("dergast");
	SetRace("human");
	SetClass("fighter");
	SetLevel(40);
  SetNoJoin(1);
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetMorality(-100);
	SetShort("Dergast, Master of the Durgoroth Arena");
	SetId( ({ "dergast","master of the arena","master" }) );
	SetLong("Dergast is a massive and bulging muscled Gorithim. "
					"His exploits as a wandering barbarian and as an gladiator "
					"are nearly legendary. Now he runs the Durgoroth arena, "
					"and indoctrinates new members of the Barbarian calling.");
	SetInventory( ([
		D_OBJ + "/2h_axe" : "wield axe",
		D_OBJ + "/plate_mail" : "wear plate mail",
		D_OBJ + "/full_helm" : "wear helmet",
		]) );
	SetCurrency("crystals", 50 + random(151));
	SetCombatAction( 35, (: DoAction :) );
	SetPlayerTitles(  ([
		"newbie" 	: "the training Fist of Durgoroth",
		"mortal" 	: "the Fist of Durgoroth",
		"hm" 			: "the Famed Basher of Durgoroth ",
		"legend" 	: "the Legendary Mauler of Durgoroth",
		"avatar" 	: "the Army Breaker of Durgoroth",
    "nomad" 	: "the Wandering Terror",
		"gladiator" : "the Gladiator of Durgoroth",
		]) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	SetFreeEquip( ([
		"/std/weapon/hack/battle_axe":1
		]) );
	}

void DoAction() {
	if(!random(3))
		toMe();
	else if(random(2))
		Splat(this_object(), this_object()->GetCurrentEnemy());
	else
		this_object()->eventForce("disarm");
	}

void Splat( object who, object target ) {
	message("splat", "Dergast screams with "
		"%^BOLD%^RED%^BLOODLUST%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
