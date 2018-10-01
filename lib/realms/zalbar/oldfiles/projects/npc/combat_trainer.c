#include <lib.h>
#include "haven.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("manar");
  SetShort("Manar Blackmane, trainer of the Haven Town Guard");
  SetId( ({ "manar", "blackmane", "manar blackmane", "trainer" }) );
  SetLong("Manar Blackmane is the trainer for the Haven Town \n"
          "Guard.  He is proficient in many weapons and has the \n"
          "knowledge of most forms of combat.");
  SetRace("elf");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(50);
  SetMorality(500);
  SetCurrency("imperials",random(300));
  SetInventory( ([
    H_OBJ + "rapier" : "wield rapier",
    ]) );
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  SetTown("Haven");
  }
