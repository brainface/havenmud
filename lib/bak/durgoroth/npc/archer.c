// Title : Durgoroth Town
// File: archer.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	Durgoroth fortress archer
//
// Revision History: 
//

#include <lib.h>
inherit LIB_NPC;
#include "../durgoroth.h"
#include "guardian.h"

void Aim();

static void create() {
	npc::create();
	SetKeyName("durgoroth archer");
	SetId( ({ "large gorithim archer","gorithim archer",
		"large gorithim","durgoroth archer","gorithim","archer",
		"guard","human" }) );
	SetShort("large Gorithim archer");
	SetLong("A large Gorithim Durgoroth fortess guard armed "
		"with a bow and set to watch out over the town and "
		"road outside the fortress. He looks more then capable "
		"of his job.");
	SetRace("human");
        SetTown("Durgoroth");
	SetClass("fighter");
	SetSkill("projectile combat", 1, 1);
	SetLevel(15 + random(16));
	SetGender("male");
	SetMorality(-50);
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		 D_OBJ + "/longbow"   : "wield bow",
		 D_OBJ + "/chainmail" : "wear chainmail",
		 D_OBJ + "/fur_cloak" : "wear cloak",
		 ]) );
	SetCurrency("crystals",40 + random(40));
	SetFriends( friends );
	SetAction( 15, "The Durgoroth Archer scans the road below the "
		"fortress.");
	SetCombatAction( 20, (: Aim :) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	}

void Aim() {
        object who = this_object();
        object target = who->GetCurrentEnemy();
        
	if(member_array("longbow", who->GetWielded()) != -1) {
		message("aim","The Durgoroth Guard takes carefull aim with "
			"his bow and looses a %^BOLD%^RED%^deadly shot%^RESET%^.",environment(who));
		who->GetWielded()[0]->eventStrike(target) + random(100);
		}
	}
