#include <lib.h>
inherit LIB_NPC;
#include "../westwood.h"
int type = random(2);

static void create() {
   npc::create();
   SetKeyName("gelfling");
   SetShort("a gelfling wanderer");
   SetId( ({ "wanderer" }) );
   SetAdjectives( ({ "gelfling" }) );
   if (type == 0) {
	SetLong("This gelfling wanders about the forest gathering food "
		"for his home in Soleil.  He seems to be dazed as he wanders "
		"about.  Perhaps he did not know the forest as well as he "
		"once thought.");
	SetGender("male");
	SetAction(8, ({
      	"!speak Hello.",
            "!speak I seem to be lost.",
            "!emote mills about the trees.",
            "!emote scans the forest for a way home.",
      }) );
   }
   if (type == 1) {
	SetLong("This female gelfling flutters about the forest, seeking "
		"a return to the days when her kind would wander the "
		"HavenWood with the elves.");
	SetGender("female");
	SetAction(8, ({
      	"!speak Hello.",
            "!speak I long for the older days.",
            "!emote flutters about the area.",
            "!emote looks thoughtful.",
      }) );
   }
   SetRace("gelfling");
   SetClass("fighter");
   SetSkill("melee combat",1,1);
   SetLevel(3);
   SetCurrency("cuicui",random(15)+15);
   SetMorality(275);
   SetReligion("Eclat","Eclat");
}
