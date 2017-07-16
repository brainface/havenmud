#include <lib.h>
inherit LIB_SAGE;
#include "../monastery.h"

static void create() {
   sage::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Geintus");
   SetShort("Geintus, the language teacher");
   SetId( ({ "geintus","teacher","language teacher" }) );
   SetLong("Geintus smiles happily at the world, facing all he "
           "meets with joy.  He has an intelligent look to him, and "
           "seems ready to teach all the knowledge he has accumulated "
           "about Oiseau.");
   SetRace("muezzin");
   SetReligion("Eclat","Eclat");
   SetClass("priest");
   SetSkill("melee combat",1,2);
   SetLevel(45);
   SetGender("male");
   SetLocalCurrency("cuicui");
   SetCharge(450);
   SetSpellBook( ([
   		"sanctify" : 100,
   		"rejuvenation" : 100,
   		]) );
   SetCombatAction(20,({ 
   		"!cast sanctify",
   		"!cast rejuvenation",
   		"!speak in oiseau Think of what you could learn and "
   		"the joy that could be spread if you had not done this!",
      }) );
   SetMorality(1000);
}