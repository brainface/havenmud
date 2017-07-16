#include <lib.h>
inherit LIB_SAGE;
#include "../monastery.h"

static void create() {
   sage::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Geintus");
   SetShort("Geintus, the language teacher");
   SetId( ({ "geintus","teacher","language teacher" }) );
   SetLong("Geintus smiles happily at the world, facing all he "
           "meets with joy.  He has an intelligent look to him, and "
           "seems ready to teach all the knowledge he has accumulated "
           "about Oiseau.");
   SetRace("muezzin");
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetClass("fighter");
   SetLevel(45);
   SetGender("male");
   SetLocalCurrency("cuicui");
   SetCharge(450);
   SetSpellBook( ([
                    "sanctify" : 100,
               ]) );
   SetCombatAction(45,({ "!cast sanctify","!speak in oiseau Think of "
                         "what you could learn and the joy that could "
                         "be spread if you had not done this!" }) );
   SetMorality(600);
}