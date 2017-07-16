// Title: Durgoroth Town
// File: uruial.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Uruial, magic trainer of Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_TRAINER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	trainer::create();
	SetKeyName("uruial");
	SetShort("Uruial Merkampa");
	SetId( ({ "uruial", "uruial merkampa", "merkampa" }) );
	SetClass("evoker");
	SetSkill("conjuring",1,1);
	SetSkill("evokation",1,1);
	SetSkill("enchantment",1,1);
	SetSkill("melee combat",1,2);
	SetLevel(25);
	SetGender("female");
	SetRace("nosferatu");
	SetMorality(-400);
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetReligion("Saahagoth");
	SetLong("This is Uruial Merkampa, she is a teacher of "
					"various magical skills.");
	SetCombatAction( 30, ({
		(: summonGuard, this_object() :),
		"!cast fireball",
		"!cast sphere",
		"!cast shock",
		}) );
	SetSpellBook( ([
		"fireball" : 100,
		"sphere"   : 100,
		"shock"    : 100,
		]) );
	SetFriends( "mortigern" );
	}
