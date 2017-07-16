// Title : Durgoroth Town
// File: sentinel.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	A nosferatu sentinel of Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_NPC;
#include "../durgoroth.h"
#include "guardian.h"

static void create() {
	npc::create();
	SetKeyName("sentinel");
	SetId( ({ "sentinel", "nosferatu" }) );
	SetShort("a Sentinel");
	SetLong("A tall muscular Nosferatu guard. He looks mean and ready "
					"for anything.");
	SetRace("nosferatu");
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
	SetClass("cavalier");
  SetLevel(35 + random(25));
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetMorality(-200);
	SetCombatAction( 10, ({
		"The Sentinel lunges forward with his fangs "
		"bared." }) );
	SetInventory( ([ 
			D_OBJ + "/blood_lance" : "wield lance",
			D_OBJ + "/wall_shield" : "wear shield on left arm" 
			]) );
	SetCurrency("crystals", 40 + random(40) );
	SetFriends( friends );
	}
