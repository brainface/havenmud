#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("andromedus");
  SetShort("Andromedus the Brute, Unarmed Champion");
  SetId( ({ "champion", "andromedus", "brute" }) );
  SetAdjectives( ({ "andromedus", "the", "unarmed" }) );
  SetRace("human");
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({ "melee combat" }) );
  SetSkill("parry",1,2);
  SetSkill("dodge",1,2);
  SetSkill("combat rage",1,2);
  
  SetInventory( ([
  	"/std/weapon/melee/cestus" : "wield cestus",
  	]) );
  
  SetGender("male");
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetMorality(-50);
  SetLong("Andromedus the Brute held the title of Champion in unarmed "
          "competition for ten years before the end of the public "
          "circuses. Though he is older now, he is still wise and "
          "willing to teach.");
  SetLimit(1);
}
