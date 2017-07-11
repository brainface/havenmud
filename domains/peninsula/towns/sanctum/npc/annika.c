#include <lib.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("annika");
  SetShort("Annika the Redeemer, Teacher of Wisdom");
  SetReligion("Eclat");
  SetTaughtSpheres( ({
    "natural healing", 
    "religion eclat", 
    "natural magic",
    "natural enchantment",
    "natural evokation",
    }) );
  SetId( ({ "annika", "redeemer", "teacher" }) );
  SetRace("human");
  SetClass("druid");
  SetSkill("melee combat",1,2);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Annika the Redeemer is responsible for the metaphysical "
          "needs of the Eclat clerics. Her teaching ways are simple "
          "and honest, with healing arts favoured over all others.");
  SetGender("female");
  
  SetLevel(48);
  SetAction(5, ({
    "!speak Would you like me to convert you?",
    "!speak If you are an Eclat druid, I can teach you spells.",
    }) );
  SetSpellBook( ([
   		"soothe" : 100,
   		"vine wall" : 100,
   		"forest banishment" : 100,
   	  ]) );
   SetCombatAction(40, ({
   		"!cast soothe",
   		"!cast vine wall",
   		"!cast forest banishment",			
    	}) );
  SetLimit(1);
}
