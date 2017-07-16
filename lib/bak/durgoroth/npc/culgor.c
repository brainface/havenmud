// Title: Durgoroth Town
// File: culgor.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Durgoroth weapon attack skill trainer
//
// Revision History: 
//

#include <lib.h>
inherit LIB_TRAINER;
#include "../durgoroth.h"
#include "rescueme.h"
#include "guardian.h"

void DoAction();

static void create() {
	trainer::create();
  SetKeyName("culgor");
  SetShort("Culgor, Weapon Master of the Arena");
  SetId( ({ "culgor", "weapons master"}) );
  SetGender("male");
  SetRace("nosferatu");
  SetClass("fighter");
  SetSkill("disorient",1,1);
  SetSkill("plate armour",1,1);
  SetSkill("combat rage",1,1);
  SetSkill("dodge",1,1);
  SetSkill("parry",1,1);
   
  SetLevel(40);
  AddTrainingSkills("slash combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("multi-weapon");
  
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
  SetMorality(-200);
  SetProperty("durgorothNPC",1);
  SetLong("This is Culgor, The weapons master of the Durgoroth "
          "arena as the chief trainer for the Durgoroth warriors. If "
          "you want to learn anything about weapons, this is the "
          "person to come to.");
  SetInventory( ([
		D_OBJ + "/katana" : "wield katana in right hand",
		D_OBJ + "/blood_sword" : "wield blood sword in left hand",
		D_OBJ + "/nosf_armour" : "wear armour",
		]) );
  SetFriends( friends );
	SetCombatAction( 30, (: DoAction() :) );
  }

void DoAction() {
	if(random(2))
		toMe();
	else
		this_object()->eventForce("disorient");
	}
