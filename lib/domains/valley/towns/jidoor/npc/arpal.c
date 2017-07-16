//
// Arpal, Evoker Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("arpal");
   SetId( ({ "arpal", "privara", "instructor","jidoor_npc", }) );
   SetAdjectives( ({ "arpal", "privara", "self", "defense" }) );
   SetShort("Arpal Privara the Self-Defense Instructor");
   SetLong("Arpal, of the Privara family, is one of the "
           "smartest men in the world. His head bulges with "
           "skill and power.");
   SetRace("sprite");
   SetTown("Jidoor");
   SetMorality(80);
   
   SetClass("evoker");
   SetSkill("conjuring",1,1);
   SetSkill("evokation",1,1);
   AddTrainingSkills("knife combat");
   AddTrainingSkills("melee combat");
   AddTrainingSkills("slash combat");
   AddTrainingSkills("pierce combat");
   AddTrainingSkills("projectile combat");
   SetLevel(20);
   SetGender("male");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   		]) );
   SetSpellBook( ([
      "missile"  : 100,
      "sphere"   : 100,
      "shock"    : 100,
      ]) );
   SetCombatAction(60, ({ 
      "!cast missile",
      "!cast sphere",
      "!cast shock",
   		}) );
}
