#include <lib.h>
#include "../soleil.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   RemoveLanguage("Eltherian");
   SetLanguage("Oiseau",100,1);
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
   SetClass("cleric");
   SetSkill("healing",1,1);
   SetSkill("melee attack",1,1);
   SetSkill("enchantment",1,1);
   SetSkill("divination",1,2);
   SetSkill("blunt defense",1,3);
   SetSkill("bargaining",1,2);
   SetSkill("slash defense",1,3);
   SetSkill("melee defense",1,3);
   SetSkill("fishing",1,2);
   SetSkill("armour smithing",1,4);
   SetSkill("weapon smithing",1,4);
   SetSkill("leather working",1,4);
   SetSkill("metal working",1,4);
   SetLevel(48);
   SetCurrency("cuicui",8000 + random(500));
   AddTrainingSkills("faith");
   AddTrainingSkills("enchantment");
   AddTrainingSkills("healing");
   AddTrainingSkills("melee attack");
   AddTrainingSkills("divination");
   AddTrainingSkills("bargaining");
   AddTrainingSkills("fishing");
   SetMorality(2000);
   SetSpellBook( ([
                    "sanctify" : 100,
                    "pious obstructions" : 100,
                    "guardian angel" : 100,
                    "awakening" : 100,
                    "bloom" : 100,
                    "sphere of happiness" : 100,
                    "harm evil" : 100,
               ]) );
   SetAction(5, ({ "!cast pious obstructions","!cast "
                   "guardian angel","!cast bloom",
                   "!cast sphere of happiness",
                   (: eventCompleteHeal(100) :),
                   "!smell first flower","!smell first flower",
                   "!say I train Eclatish clerics.",
                   "!say I train any Eclat with the "
                   "skills of our clerics.",
                   "!say If you become an Eclat, I can "
                   "help you.",
                   "!say Kiee will help you become an "
                   "Eclat.  Just ask her to convert you.  "
                   "She is in the temple, in the southeast "
                   "corner of the first level of platforms.",
                   "!say Soleil is a beautiful city.",
                   "!say Kiee would be glad to convert you to "
                   "Eclat.  I'm on the same platform level "
                   "as her; she's just south and east from "
                   "here usually." }) );
   SetCombatAction(40, ({ "!trip","!trip","!cast sanctify",
                          "!cast harm evil","!cast harm evil",
                          "!cast harm evil","!yell Help me!",
                          "!say Get away from me!",
                          "!say Stop this, scoundrel!",
                          "!say Rascal!  Knave!  Ignorant fool!",
                          "!say Wretched scamp!  Cease your attacks!",
                          "!yell Someone come help me!  I'm being "
                          "attacked!","!trip","!cast harm evil" }) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
