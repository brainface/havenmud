#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("commodus");
  SetShort("Commodus Maximus, Master of Swords");
  SetId( ({ "commodus", "maximus", "master", "swordsmaster" }) );
  SetAdjectives( ({ "commodus", "master", "swords", "sword" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({ 
    "slash combat", 
    "multi-weapon",
    }) );
  SetGender("male");
  SetSkill("parry",1,2);
  SetSkill("dodge",1,2);
  SetSkill("combat rage",1,2);
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetTown("Sanctum");
  SetMorality(-50);
  SetLong("Commodus is the SwordsMaster of the Sanctum Colosseum. "
          "He excels in all forms of slash weaponry, and is willing "
          "to train any person dedicated and willing to learn.");
  SetInventory( ([
  	"/std/weapon/sword" : 2,
  	]) );
  SetFirstCommands( ({
  	"wield swords"
  	}) );
  SetLimit(1);
}
