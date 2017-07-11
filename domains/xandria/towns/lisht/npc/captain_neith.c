//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("Captain Neith");
  SetShort("Captain Neith, Trainer of Lisht");
  SetId( ({ "neith", "trainer", "captain" }) );
  SetAdjectives( ({ "captain" }) );
  SetLong(
    "Neith is the Trainer of all fighters of Lisht. She seems quite "
    "sturdy and knowledgeable in many forms of combat. Her eyes are "
    "crimson, as if stained with the blood of failed students. She "
    "is no person to cross wisely.");
  SetRace("gnoll");
  SetGender("female");
  SetClass("cavalier");
  SetLevel(50);
  SetCurrency("deben",random(500));
  SetInventory( ([
    LISHT_OBJ "b_sword" : 2,
    LISHT_OBJ "b_armour" : "wear armour",
    LISHT_OBJ "shenti" : "wear shenti",
    ]) );
SetFirstCommands( ({ "wield swords" }) );
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("hack combat");
  SetTown("Lisht");
  SetBaseLanguage("Rehshai");
  }
