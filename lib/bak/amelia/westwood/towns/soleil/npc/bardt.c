#include <lib.h>
#include "../soleil.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Harmony");
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetShort("Harmony, the music teacher");
   SetId( ({ "harmony","teacher" }) );
   SetAdjectives( ({ "music" }) );
   SetLong("Harmony is Melody's twin sister.  "
           "Melody is the bard leader in Soleil.  "
           "Harmony's fur is dark brown, and her "
           "eyes match the fur color nicely.  She "
           "appears to be very musical, and can't "
           "keep herself from humming.");
   SetGender("female");
   SetClass("bard");
   SetRace("muezzin");
   SetLevel(40);
   AddTrainingSkills("vocal music");
   AddTrainingSkills("instrumental music");
   AddTrainingSkills("bargaining");
   AddTrainingSkills("healing");
   SetSongBook( ([
                   "spiccato" : 100,
                   "ballad of autumn" : 100,
                   "ballad of summer" : 100,
                   "pianississimo" : 100,
                   "harmonic shield" : 100,
                   "lunar ballad" : 100,
                   "solar ballad" : 100,
                   "tingling song" : 100,
              ]) );
   SetAction(5, ({ "!sing harmonic shield"
                   "!sing lunar ballad",
                   "!sing solar ballad",
                   "!say I train bards.",
                   "!say I can help you learn "
                   "more about singing, playing "
                   "instruments, bargaining "
                   "with the vendors of the world, "
                   "and healing the sick and lame.",
                   "!say If you want to become a "
                   "bard, go visit my sister "
                   "Melody!  She is usually in "
                   "the town hall.","!say Only "
                   "Eclats may learn from me.",
                   "!say It's a beautiful world!",
                   "!say If you want to become a "
                   "chorists, visit Kiee and Melody "
                   "both.  Kiee is in the temple, "
                   "and Melody likes the town hall.",
                   "!say Joy to everyone!" }) );
   SetCombatAction(40, ({ "!shout Help me!  I'm "
                   "being attacked!","!say Get "
                   "away from me you fiend!",
                   "!say Stop this terrible act!",
                   "!sing spiccato","!sing ballad of "
                   "autumn","!sing ballad of summer",
                   "!sing pianississimo","!sing "
                   "tingling song","!sing harmonic "
                   "shield" }) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
