//
// Parcil, Diviner Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("parcil");
   SetId( ({ "parcil", "privara", "parcil privara","jidoor_npc", }) );
   SetShort("Parcil Privara");
   SetLong("Parcil Privara is of the legendary Privara "
           "family. His skillfulness is world renowned.");
   SetRace("sprite");
   SetGender("male");
   
   SetClass("evoker");
   SetSkill("conjuring",1,1);
   SetSkill("evokation",1,1);
   SetSkill("conjuring",1,1);
   AddTrainingSkills("blunt combat");
   AddTrainingSkills("mithril working");
   SetLevel(20);
   SetMorality(80);
   SetReligion("Magildan","Magildan");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals"      : "wear sandals",
      STD_BLUNT + "mace" : "wield mace",
   		]) );
   	SetSpellBook( ([
      "ice ball" : 100,
      "sphere"   : 100,
      "shock"    : 100,
      ]) );
   SetCombatAction(60, ({ 
      "!cast ice ball",
      "!cast sphere",
      "!cast shock",
   		}) );	
   	
}
