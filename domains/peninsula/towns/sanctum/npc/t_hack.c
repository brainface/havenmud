#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("celtigern");
  SetShort("Celtigern the Barbarian, Master of the Axe");
  SetId( ({ "celtigern", "barbarian", "axe", "master" }) );
  SetAdjectives( ({ }) );
  SetRace("gnoll");
  SetRaceRestricted(0);
  RemoveLanguage("Heyami");
  SetTown("Sanctum");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({
    "hack combat", 
    "multi-weapon",
    }) );
  SetGender("male");
  SetSkill("combat rage",1,2);
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  
  SetInventory( ([
  	"/std/weapon/hack/battle_axe" : "wield axe",
  	]) );
  
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetMorality(-50);
  SetLong("Celtigern the Barbarian was captured as a young pup "
          "from his tribe far north of Sanctum. His ugly visage "
          "looks like a hideous cross between a dog and a man. "
          "Though he is the master of the axe, many fear training "
          "with him.");
  SetLimit(1);
}
