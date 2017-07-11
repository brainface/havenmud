//
// Purcil, Necromancer Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("purcil");
   SetId( ({ 
   		"purcil", "privara", "purcil privara","teacher" 
   		"jidoor_npc",
   		}) );
   SetShort("Purcil Privara"); 
   SetLong("This is Purcil, local teacher of "
           "various skills to all necromancers.");
   
   SetClass("necromancer");
   SetSkill("necromancy",1,1);
   SetSkill("conjuring",1,1);
   SetSkill("evokation",1,1);
   AddTrainingSkills("knife combat");
   AddTrainingSkills("skinning");
   SetMorality(-50);
   SetTown("Jidoor");
 
   SetLevel(20);
   SetGender("male");
   SetRace("sprite");
  
   SetReligion("Magildan","Magildan");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_necro_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      ]) );
   SetSpellBook( ([
   		"wound"       : 100,
   		"acid blast"  : 100,
   		"bone shell"  : 100,
   	  ]) );
   SetCombatAction(40, ({
   	  "!cast wound",
   	  "!cast acid blast",
   	  "!cast bone shell",
   		}) );  
    
}
