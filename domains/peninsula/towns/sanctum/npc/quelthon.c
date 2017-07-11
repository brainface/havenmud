#include <lib.h>
#include "../rome.h"
inherit LIB_METATRAINER;

static void create() {
  ::create();
  SetKeyName("torin");
  SetShort("Torin the Mendicant, Acolyte of Kylin");
  SetReligion("Kylin");
  SetId( ({ "torin", "mendicant" }) );
  SetTaughtSpheres( ({
    "clerical", 
    "religion kylin",
    "clerical enchantment", 
    "clerical healing",
    }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Torin the Mendicant is an Acolyte of Kylin.  He serves at "
          "the pleasure of Matathan. His primary job is to convert new "
          "members to the Kylin religion and teach the priests of Kylin "
          "to cast spells based on their faith.");
  SetGender("male");
  SetTown("Sanctum");
  SetClass("priest");
  SetLevel(30);
  SetAction(5, ({
    "!speak Would you like me to convert you?",
    "!speak If you are a priest of Kylin, I can teach you spells.",
    "!cast fidei defensor",
    }) );
  SetSpellBook( ([
    "fidei defensor" : 100,
    "wrath" 			   : 100,
    ]) );
  SetCombatAction(40, ({
    "!cast fidei defensor",
    "!cast wrath",
    }) );
  SetLimit(1);
}
