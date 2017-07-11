#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("Diego");
  SetShort("Diego the Apprentice");
  SetId( ({ "diego", "apprentice", "trainer" }) );
  SetAdjectives( ({ "apprentice" }) );
  SetLong(
    "Diego is a like the son Carlos never had. Diego is here learning "
    "all he can from Carlos in exchange for doing minor choirs. If you "
    "are willing to learn, Diego can teach a few skills that Carlos "
    "taught him." 
    );
  SetRace("human");
  SetGender("male");
  SetClass("merchant");
  SetSkill("melee combat",1,3);
  SetLevel(20);
  SetCurrency("oros", 500);
  //SetInventory();
  //SetCombatAction();
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("metal working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  SetTown("Parva");
}
