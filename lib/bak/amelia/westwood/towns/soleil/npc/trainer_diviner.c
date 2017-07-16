#include <lib.h>
#include "../soleil.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetKeyName("Neca");
   SetMorality(300);
   SetShort("Neca, the Diviner Trainer");
   SetId( ({ "neca","diviner","trainer" }) );
   SetAdjectives( ({ "neca","the","diviner","trainer" }) );
   SetLong("Neca appears willing to talk to all those "
           "who are diviners about "
           "their discipline, but will only teach "
           "Eclats.  She is tall and willowy with "
           "slightly pointed ears, and appears to "
           "be strong in her talents.");
   SetRace("gelfling");
   SetClass("diviner");
   SetGender("female");
   SetLevel(40);
   AddTrainingSkills("divination");
   AddTrainingSkills("conjuring");
   AddTrainingSkills("blund defense");
   AddTrainingSkills("blunt attack");
   AddTrainingSkills("necromancy");
   AddTrainingSkills("planar magic");
   RemoveLanguage("Eltherian");
   SetLanguage("Oiseau",90,1);
   SetAction(3, ({ "!speak This is such a lovely "
                   "home that Nobu owns.",
                   "!speak I love visiting around "
                   "this town.",
                   "!speak The red roses themselves "
                   "all alone would be gorgeous, "
                   "but with blue roses too it's an "
                   "artistic statement!",
                   "!speak The thorns accentuate "
                   "the color and give meaning "
                   "to the window.",
                   "!speak The clear color in the "
                   "middle is a window to the "
                   "outside world, and as it is, "
                   "full of beauty and danger, "
                   "so does the stain glass "
                   "speak.",
                   "!speak How I love analyzing "
                   "art like this!",
                   "!smile" }) );
   SetCombatAction(40, ({ "!shout Help!",
                          "!shout Help, I'm being "
                          "attacked!","!say Please, "
                          "whoever you are, cease "
                          "this senseless violence!",
                          "!speak Help!",
                          "!say Nobu!","!say Help me!",
                          "!say Get away from me!",
                          "!shout Fellow Soleil "
                          "citizens, come quickly!",
                  }) );
   SetInventory( ([
                    S_OBJ + "sceptre_rose" : "wield sceptre",
               ]) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
