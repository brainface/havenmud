#include <lib.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("suvraela");
  SetShort("Suvraela the Druid of Eclat");
  SetId( ({ "suvraela", "druid" }) );
  SetLong("Suvraela the Druid is responsible for the metaphysical "
          "needs of the Eclat druids. Her teaching ways are simple "
          "and honest, with healing arts favoured over all others.");
  
  SetTown("Haven");
  SetReligion("Eclat");
  SetMorality(1250);
  SetRace("elf");
  SetGender("female");
  SetClass("druid");
  SetSkill("melee combat",1,2);
  SetLevel(30);
  SetCurrency("imperials", 100);
  SetAction(5, ({
    "!speak Would you like me to convert you?",
    "!speak If you are an Eclat Druid, I can teach you spells.",
    }) );
  SetSpellBook( ([
  	"soothe"		   : 100,
  	"natural veil" : 100,
  	"terra"        : 100,
  	"color spray"  : 100,  
    ]) );
  SetCombatAction(50, ({
  	"!cast soothe",
  	"!cast natural veil",
  	"!cast terra",
  	"!cast color spray",
    }) );
  SetLimit(1);
}
