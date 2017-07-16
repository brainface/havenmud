#include <lib.h>
inherit LIB_TRAINER;
#include "../soleil.h"

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetKeyName("Nascima");
   SetShort("Nascima, a trainer");
   SetMorality(500);
   SetId( ({ "nascima","trainer","ranger" }) );
   SetAdjectives( ({ "ranger","trainer" }) );
   SetLong("Nascima trains rangers primarily, but some other people may "
           "find her knowledge of projectile attack and defense, "
           "slash attack, healing, stealth, multi-weapon, "
           "and wood working to be useful.  She is a short brown muezzin "
           "of average build, but knows her skills well, though not "
           "enough to rival Foret, the ranger trainer in Soleil.");
   SetRace("muezzin");
   SetClass("ranger");
   SetGender("female");
   SetLevel(28);
   AddTrainingSkills("projectile attack");
   AddTrainingSkills("projectile defense");
   AddTrainingSkills("slash attack");
   AddTrainingSkills("natural magic");
   AddTrainingSkills("healing");
   AddTrainingSkills("stealth");
   AddTrainingSkills("multi-weapon");
   AddTrainingSkills("wood working");
   SetInventory( ([
                    S_OBJ + "cross_s" : "wield crossbow in right hand",
               ]) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
