// Title: Durgoroth Town
// File: shamfast.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Durgoroth weapon defense skill trainer
//
// Revision History: 
//

#include <lib.h>
inherit LIB_TRAINER;
#include "../durgoroth.h"
#include "rescueme.h"
#include "guardian.h"

static void create() {
	trainer::create();
	SetKeyName("shamfast");
	SetShort("Shamfast, Defense Master of Durgoroth");
	SetId( ({ "shamfast","defense master"}) );
	SetClass("fighter");
	SetLevel(35);
	AddTrainingSkills("slash combat");
	AddTrainingSkills("hack combat");
	AddTrainingSkills("pierce combat");
	AddTrainingSkills("blunt combat");
	AddTrainingSkills("pole combat");
	AddTrainingSkills("knife combat");
	AddTrainingSkills("melee combat");
	AddTrainingSkills("projectile combat");
	SetGender("male");
	SetRace("human");
  SetTown("Durgoroth");
	SetMorality(-100);
	SetProperty("durgorothNPC",1);
	SetLong("Shamfast is an old and experienced warrior. He is the "
					"defense master of Durgoroth's arena. It is roumored that "
					"there is no attack for which he does not have the counter. "
					"If you wish to learn anything about the arts of defense "
					"this would be the man to talk to.");
	SetInventory( ([
		D_OBJ + "/blood_sword" : "wield sword in right hand",
		D_OBJ + "/nosf_armour" : "wear armour",
		D_OBJ + "/wall_shield" : "wear shield on left arm",
		]) );
	SetFriends( friends );
	SetCombatAction( 20, (: toMe, this_object() :) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	}
