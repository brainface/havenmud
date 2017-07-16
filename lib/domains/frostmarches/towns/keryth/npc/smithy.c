#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Farvse");
  SetShort("Farvse the Smith");
  SetId( ({ "farvse", "smith" }) );
  SetAdjectives( ({ "goden" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetLevel(50);
  SetMorality(-100);
  SetGender("male");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  SetLong("Farvse is a small limber goden who looks to be quiet young. "
         "His fur is light grey color with some orange striations. He would "
         "teach a citizen how to repair and maintain armour and weapons if asked."
         );
}
