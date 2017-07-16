#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("tyrranus");
  SetShort("Tyrranus Maximus, Master of the Rapier");
  SetId( ({ "tyrranus", "maximus", "master", "swordsmaster" }) );
  SetAdjectives( ({ "tyrranus", "master", "rapiers", "rapier" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({
    "pierce combat", 
    "multi-weapon",
    }) );
  SetTown("Sanctum");
  SetGender("male");
  SetSkill("parry",1,2);
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  
  SetInventory( ([
  	"/std/weapon/pierce/rapier" : "wield rapier",
  	]) );
  
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetMorality(-50);
  SetLong("Tyrranus is the Rapier Trainer of the Sanctum Colosseum. "
          "He excels in all forms of pierce weaponry, and is willing "
          "to train any person dedicated and willing to learn.");
  SetLimit(1);
}
