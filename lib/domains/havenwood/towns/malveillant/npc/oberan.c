/*  Portia  10-23-98
   A trainer for the hall of Defense in Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("oberan");
  SetShort("Oberan the Master of Defense");
  SetId( ({"oberan", "master"}) );
  SetAdjectives( ({"master"}) );
  SetLong("Oberan is an enormous dark-elf, with branch-sized arms, "
          "and trunk sized legs, he towers over almost all beings on "
          "Kailie. He looks as if he is very skilled in the secrets of "
          "battle.");
  SetTown("Malveillant");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetGender("male");
  SetClass("fighter");
  SetSkill("cloth armour",1,1);
  SetLevel(90);
  SetCurrency("roni",random(850) + 50);
  SetStat("wisdom", 1000, 1);
  SetAction(7, ({
      "!say would you like to learn how to defend yourself?"
      }) );
  SetCombatAction(10, ({
  		"!disarm",
  		"!disorient",
  		"!yell Die scum!",
  		}) );
  SetInventory( ([
      MAL_OBJ + "/clothing/g_boots"     : "wear boots",
      MAL_OBJ + "/clothing/g_pants"     : "wear pants",
      MAL_OBJ + "/clothing/g_medallion" : "wear medallion",
      MAL_OBJ + "/clothing/lead_plate"  : "wear breastplate",
      MAL_OBJ + "/weapons/gl_sword"     : "wield sword",
       ]) );
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("cooking");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("leather working");  
  AddTrainingSkills("metal working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("natural working");
  }
