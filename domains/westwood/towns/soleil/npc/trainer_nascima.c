#include <lib.h>
inherit LIB_TRAINER;
#include "../soleil.h"

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetKeyName("Nascima");
   SetShort("Nascima, a trainer");
   SetMorality(1000);
   SetId( ({ "nascima","trainer","ranger" }) );
   SetAdjectives( ({ "ranger","trainer" }) );
   SetLong("Nascima trains rangers primarily, but some other people may "
           "find her knowledge of projectile combat, "
           "slash combat, healing, stealth, multi-weapon, "
           "and wood working to be useful.  She is a short brown muezzin "
           "of average build, but knows her skills well, though not "
           "enough to rival Foret, the ranger trainer in Soleil.");
   SetRace("muezzin");
   SetClass("ranger");
   SetGender("female");
   
   AddTrainingSkills("projectile combat");
   AddTrainingSkills("slash combat");
   AddTrainingSkills("metal working");
   AddTrainingSkills("mithril working");
   AddTrainingSkills("leather working");
   AddTrainingSkills("textile working");
   AddTrainingSkills("natural working");
   AddTrainingSkills("armour smithing");
   AddTrainingSkills("weapon smithing");
   AddTrainingSkills("slash combat");
   AddTrainingSkills("stealth");
   AddTrainingSkills("multi-weapon");
   AddTrainingSkills("wood working");
   SetLevel(30);
   SetInventory( ([
                    S_OBJ + "cross_s" : "wield crossbow in right hand",
               ]) );
   SetSpellBook( ([
   		"natural veil"	 : 100,
   		"natural charge" : 100,
   		"freeze"	  	   : 100,
   		"heat"					 : 100,
   		]) );
   SetCombatAction(25, ({
   	  "!cast natural veil",
   	  "!cast natural charge",
   	  "!cast freeze",
   	  "!cast heat",
   		}) );     
          
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
