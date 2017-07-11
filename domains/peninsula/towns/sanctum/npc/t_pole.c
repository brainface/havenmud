#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("robin");
  SetShort("Robin of Eclat, Quarterstaff Mistress");
  SetId( ({ "robin", "mistress" }) );
  SetAdjectives( ({ "quarterstaff", "staff" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({
    "pole combat", 
    "multi-weapon",
    "blunt combat",
    }) );
  SetTown("Sanctum");
  SetGender("female");
  SetSkill("parry",1,2);
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  
  SetInventory( ([
  	"/std/weapon/staff" : "wield staff",
  	]) );
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetMorality(-50);
  SetLong("Robin of Eclat is a pious looking older woman, peaceful "
          "and serene in her contemplations. She is famous for her "
          "abilities with pole weapons such as spears and staves. "
          "She is, like all the Masters of the Colosseum, willing to "
          "teach anyone who is willing to learn.");
  SetLimit(1);
}
