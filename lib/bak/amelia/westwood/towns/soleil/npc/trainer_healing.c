#include <lib.h>
#include "../soleil.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetRace("halfling");
   RemoveLanguage("Eltherian");
   SetMorality(500);
   SetReligion("Eclat","Eclat");
   SetLanguage("Oiseau",100,1);
   SetKeyName("Hanan");
   SetShort("Hanan, the cook");
   SetId( ({ "hanan","cook" }) );
   SetAdjectives( ({ "hanan","the","cook" }) );
   SetLong("Hanan is a short, fat halfling with "
           "small blue eyes and a mop of shaggy "
           "blond hair.  He has a number of "
           "quickly healing burns on his body, "
           "and looks like he might be willing to "
           "train others in something.");
   SetClass("valkyr");
   SetSkill("healing",1,1);
   SetGender("male");
   SetLevel(20);
   AddTrainingSkills("healing");
   SetCurrency("cuicui",5000);
   SetAction(10, ({ "!emote putzes around the kitchen.",
                    "!emote looks around for some ingredients.",
                    "!emote mixes something in a big bowl.",
                    "!emote yowls as he burns his finger, "
                    "and quickly begins to use his great "
                    "healing skill to fix himself up.",
                    "!say Being in a kitchen, with all sorts "
                    "of sharp and hot things around, "
                    "one has to be a good healer.  I can teach "
                    "people more about healing if you're interested."
               }) );
   SetCombatAction(30, ({ "!trip","!trip","!shout help!",
                          "!yell Help me someone!",
                          "!say Stop that scoundrel!",
                          "!say Get away from me!" }) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
