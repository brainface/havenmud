#include <lib.h>
#include <domains.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("lilia");
  SetShort("Lilia Ravenhair, Trainer of Clerics");
  SetReligion("Soirin");
  SetTaughtSpheres( ({
    "clerical necromancy", 
    "religion soirin", 
    "clerical",
    "clerical evokation",
    }) );
  SetUniqueSkills( ([
       ]) );
  SetId( ({ "lilia", "ravenhair", "trainer" }) );
  SetAdjectives( ({ "lilia" }) );
  SetRace("human");
  RemoveLanguage("human");
  SetLanguage("Imperial", 100, 1);
  SetLong("Lilia Ravenhair is responsible for the metaphysical "
          "needs of the Soirin clerics. Her teaching ways are simple "
          "and effective, with enchanting arts favoured over all others.");
  SetGender("female");
  SetTown("Sanctum");
  SetClass("priest");
  SetSkill("poison magic",1,2);
  SetUniqueSkills( ([
    "blunt combat"  : 0,
    "pierce combat" : 1,
    "stealth"       : 2,
    ]) );
  SetLevel(40);
  SetAction(5, ({
    "!speak Would you like me to convert you?",
    "!speak If you are a Soirin priest, I can teach you spells.",
    }) );
  SetInventory( ([
  	HAVENWOOD_TOWNS + "malveillant/obj/clothing/cler_medallion" : "wear medallion",
    HAVENWOOD_TOWNS + "malveillant/obj/weapons/elf_rapier" : "wield rapier",
    ]) );
  SetSpellBook( ([
    "harm body"       : 100,
    "poison arrow"    : 100,
    "shield of faith" : 100,
    "pain touch"      : 100,
    ]) );
  SetCombatAction(40, ({
    "!cast harm body",
    "!cast poison arrow",
    "!cast shield of faith",
    "!cast pain touch"
    }) );  
  SetPlayerTitles( ([
      "newbie" : "the Tempted",
      "mortal" : "the Wielder of the Black Rose",
      "hm"     : "the Divine Theorist of Avarice",
      "legend" : "the Zealous Preacher of Lust",
      "avatar" : "the Ravenous Hierophant",
       ]) );
  SetLimit(1);
}
