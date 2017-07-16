#include <lib.h>
inherit LIB_NPC;
#include "../westwood.h"
int type = random(2);

static void create() {
   npc::create();
   SetKeyName("halfling");
   SetShort("a halfling wanderer");
   SetId( ({ "wanderer" }) );
   SetAdjectives( ({ "halfling" }) );
   if (type == 0) {
	SetLong("This halfling appears to be lost deep in the WestWood.  "
		"His belly is round like most halflings and he is very "
		"short.");
	SetGender("male");
	SetAction(8, ({
      	"!speak Greetings.",
            "!speak I am getting hungry.",
            "!mutter",
            "!emote rubs his stomach thoughtfully.",
      }) );
   }
   if (type == 1) {
	SetLong("This female halfling wanders around looking for Soleil.  "
		"It seems as though she stepped away from town for a short "
		"and can not find her way back.");
	SetGender("female");
	SetAction(8, ({
      	"!speak I hate getting lost in this forest.",
            "!smile",
            "!emote complains under her breath.",
      }) );
   }
   SetRace("halfling");
   SetClass("fighter");
   SetLevel(3);
   SetCurrency("cuicui",random(50)+15);
   SetMorality(75);
   SetReligion("Eclat","Eclatish");
}
