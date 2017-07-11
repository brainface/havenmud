//
// Porcil, Enchanter Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("porcil");
   SetShort("Porcil Privara");
   SetId( ({ "porcil", "privara", "porcil privara","jidoor_npc",}) );
   SetTown("Jidoor");
  
   SetClass("enchanter");
   SetSkill("enchantment",1,1);
   SetSkill("conjuring",1,1);
   SetSkill("evokation",1,1);
   AddTrainingSkills("pole combat");
   AddTrainingSkills("textile working");
   SetLevel(20);
   SetMorality(80);
   SetGender("female");
   SetRace("sprite");
   SetLong("This is Porcil, local teacher of "
           "various skills to all enchanters.");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      STD_POLE + "staff" : "wield staff",
      ]) );
   SetSpellBook( ([
      "ice ball" : 100,
      "aura"     : 100,
      "shock"    : 100,
      ]) );
   SetCombatAction(60, ({ 
      "!cast ice ball",
      "!cast aura",
      "!cast shock",
   		}) );

}
