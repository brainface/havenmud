// Title : Durgoroth Town
// File: elite_guard.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	An elite Saa'HaGoth guard of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_NPC;
#include "../durgoroth.h"
#include "guardian.h"

int CheckStatus( object who );

static void create() {
	npc::create();
	SetKeyName("elite guard");
	SetId( ({ "elite Saahagoth guard","Saahagoth guard","guard" }) );
	SetShort("an elite guard of Saahagoth");
	SetLong("This guard is part of Morgul's elite guard. They are "
		"fanatically faithful to Saahagoth, and this guard looks "
		"more then capable of destroying any heretic or invader.");
	SetRace("nosferatu");
  SetTown("Durgoroth");
  SetClass("fighter");
	SetReligion("Saahagoth","Saahagoth");
	SetLevel(40);
	if(random(3))
		SetGender("male");
	else
		SetGender("female");
	SetMorality(-500);
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		 D_OBJ + "/katana" 			: "wield katana",
		 D_OBJ + "/blood_sword" : "wield blood sword",
		 D_OBJ + "/nosf_armour" : "wear armour",
		 D_OBJ + "/wall_shield" : "wear shield on left arm",
		]) );
	SetCurrency("crystals", 100 + random(300));
	SetCombatAction(25, ({
		"!disarm",
		"!disorient",
		}) );
	SetFriends( friends );
	SetEncounter((: CheckStatus :));
	}

int CheckStatus( object who ) {
	if ( this_player()->GetProperty("morgul_attacker")) {
		this_object()->eventForce("say Die scum!");
		return 1;
		}
	return 0;
	}
