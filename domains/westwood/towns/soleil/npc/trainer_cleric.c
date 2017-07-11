#include <lib.h>
#include "../soleil.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   
   
   SetKeyName("Miriam");
   SetShort("Miriam, the Eclatish Cleric Trainer");
   SetId( ({ "miriam","cleric","trainer","eclat" }) );
   SetAdjectives( ({ "miriam","the","eclatish","cleric","trainer" }) );
   SetLong("Miriam has a pleasant, content look.  She is "
           "an Eclatish cleric, and has committed her life "
           "to training other such clerics in their skills.  "
           "She is tall and rather rounded, but looks to "
           "be highly talented.");
   SetGender("female");
   SetRace("gelfling");
   SetClass("priest");
   SetSkill("melee combat",1,1);
   RemoveLanguage("Eltherian");
   SetLanguage("Oiseau",100,1);
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetLevel(50);
   SetCurrency("cuicui",30 + random(20));
   AddTrainingSkills("melee combat");
   AddTrainingSkills("bargaining");
   AddTrainingSkills("fishing");
   SetMorality(2000);
   SetSpellBook( ([
      "sanctify" : 100,
      ]) );
   SetAction(5, ({ 

      "!say I train Eclatish clerics.",
      "!say I train any Eclat with the skills of our clerics.",
      "!say If you become an Eclat, I can help you.",
      "!say Kiee will help you become an Eclat.  Just ask her to convert you. "
          "She is in the temple, in the southeast corner of the first level of "
          "platforms.",
      "!say Soleil is a beautiful city.",
      "!say Kiee would be glad to convert you to Eclat.  I'm on the same "
      	  "platform level as her; just leave the gallery and enter the temple "
      	  "to find her."
      }) );
   SetCombatAction(40, ({ 
   		"!cast sanctify",
      "!say Get away from me!",
      "!say Stop this, scoundrel!",
      "!say Rascal!  Knave!  Ignorant fool!",
      "!say Wretched scamp!  Cease your attacks!",
      "!yell Someone come help me!  I'm being attacked!",
      "!trip",
      }) );
}

/*
int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
*/
