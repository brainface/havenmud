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
   SetRace("muezzin");
   SetClass("bard");
   SetLevel(40);
   SetSongBook( ([
      "staccato" 				 : 100,
      "ballad of autumn" : 100,
      "ballad of summer" : 100,
      "ballad of winter" : 100,
      "pianissimo" 		   : 100,
      "aural shield" 		 : 100,
      "vibration of destruction" : 100,
      "melodic allure" 	 : 100,
      ]) );
   SetAction(5, ({ 
   		"!sing aural shield"
      "!say I train bards.",
      "!say I can help you learn more about singing, playing "
          "instruments, bargaining with the vendors of the world, "
          "and healing the sick and lame.",
      "!say If you want to become a bard, go visit my sister "
          "Melody!  She is usually in the town hall.",
      "!say Only Eclats may learn from me.",
      "!say It's a beautiful world!",
      "!say If you want to become a chorists, visit Kiee and Melody "
          "both.  Kiee is in the temple, and Melody likes the town hall.",
      "!say Joy to everyone!" 
      }) );
   SetCombatAction(40, ({ 
   	  "!shout Help me!  I'm being attacked!",
   	  "!say Get away from me you fiend!",
      "!say Stop this terrible act!",
      "!sing staccato",
      "!sing ballad of autumn",
      "!sing ballad of summer",
      "!sing ballad of winter",
      "!sing pianissimo",
      "!sing vibration of destruction",
      "!sing aural shield",
      "!sing melodic allure",
      }) );
}

int eventTrain(object who, string verb, string skill) {
   if(who->GetReligion() != "Eclat") {
      eventForce("speak Sorry, I only help those of the Eclat faith.");
      return 0;
   }
   return ::eventTrain(who, verb, skill);
}
