#include <lib.h>
#include "../dalnairn.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("valgan");
  SetShort("Valgan, Master Tradesman");
  SetId( ({ "valgan", "master", "tradesman", "dalnairn_people"}) );
  SetAdjectives( ({ "valgan", "master"}) );
  SetLong("Valgan is the Master Tradesman of Dalnairn.  He is retired from "
    "crafting armour and weapons but gets a portion of Drostan's sales.  "
    "Valgan is more than willing to teach those skills which made him "
    "wealth to those who are prepared to <ask>."
    );
  SetRace("dark-dwarf");
  SetClass("fighter");
  SetSkill("blunt combat",1,2);
  SetSkill("chain armour",1,2);
  SetSkill("dodge",1,2);
  SetSkill("combat rage",1,1);
  SetSkill("accuracy",1,2);
  SetSkill("parry",1,2);

  SetGender("male");
  SetTown("Dalnairn");
  SetLevel(50);
  AddTrainingSkill("mining");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  
  SetInventory( ([
    DAL_OBJ "guardarmour" : "wear armour",
    DAL_OBJ "hammer"      : "wield hammer",
    DAL_OBJ "hsteelhelm"  : "wear helm",
    DAL_OBJ "hsteelboots" : "wear boots",
    ]) );
  SetMorality(-1000);
  SetCurrency("shards", 200);
}
