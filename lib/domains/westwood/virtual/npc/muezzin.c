#include <lib.h>
inherit LIB_NPC;
#include "../westwood.h"
int type = random(2);

static void create() {
   npc::create();
   SetKeyName("muezzin");
   SetShort("a muezzin wanderer");
   SetId( ({ "wanderer" }) );
   SetAdjectives( ({ "muezzin" }) );
   if (type == 0) {
	SetLong("The tired face of this meuzzin scans the forest.  He spends "
	"days wandering the WestWood and his nights sleeping under the stars.");
	SetGender("male");
	SetAction(8, ({
      	"!speak I love this forest.",
        "!speak Sleeping under the stars is so pleasant.",
        "!emote scans the forest.",
        }) );
   }
   if (type == 1) {
	SetLong("The tired face of this meuzzin scans the forest.  She spends "
	"her days awaiting the return of her love from the WestWood.");
	SetGender("female");
	SetAction(8, ({
      	"!speak Hello.",
        "!speak I wish my love would return to me.",
        "!emote scans the forest.",
      	}) );
   }
   SetRace("muezzin");
   SetClass("fighter");
   SetSkill("melee combat",1,2);
   SetLevel(5);
   SetCurrency("cuicui",random(50)+ 5);
   SetMorality(275);
   SetReligion("Eclat","Eclat");
}
