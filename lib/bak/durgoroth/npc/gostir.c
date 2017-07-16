// Title: Durgoth Town
// File: gostir.c
// Author: Tim Morris aka Morgoth@Haven
// Date: April 1998
//
// Abstract: Gostir Nimanaur, clerical skill trainer of Saa'HaGoth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_TRAINER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	trainer::create();
	SetKeyName("gostir");
	SetShort("Gostir Nimanaur, Priest of Saahagoth");
	SetId( ({"gostir","gostir nimanaur","nimanaur","priest" }) );
	SetLong("This is Gostir Nimanaur, he is a local teacher of "
					"clerical skills.");
 	SetGender("male");
	SetRace("nosferatu");
	SetClass("priest");
  SetSkill("necromancy",1,1);
  SetSkill("faith",1,1);
  SetSkill("evokation",1,1);
  SetSkill("melee combat",1,1);
	SetLevel(25);
	
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
	SetMorality(-1500);
	SetSpellBook( ([
		"shockwave" 	 					: 100,
		"asphyxiation" 					: 100,
		"jolt"				 				 	: 100,
		"aegis of the faithful" : 100,
		]) );
	SetCombatAction( 50, ({
		(: summonGuard, this_player() :),
		"!cast shockwave",
		"!cast asphyxiation",
		"!cast jolt",
		"!cast aegis of the faithful",
		}) );
  SetFriends( ({ "morgul", "razarac" }) );
	}
