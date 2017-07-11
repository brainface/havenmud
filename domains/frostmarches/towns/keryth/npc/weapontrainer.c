#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Olga");
  SetShort("Olga the Valkyrie");
  SetId( ({ "olga","valkyrie" }) );
  SetAdjectives( ({ "goden" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetClass("viking");
  SetSkill("melee combat",1,2);
  SetLevel(50);
  SetMorality(-100);
  SetGender("female");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("stealth");
  AddTrainingSkills("lockpicking");

  SetInventory( ([
    STD_HACK "large_axe" : "wield axe",
    STD_SLASH "sword" : "wield sword",
  ]) );

  SetLong(
    "This immense and brutish woman towers over most "
    "of the other citizens of Keryth. Known as the Valkyrie "
    "for her prowess in battle against the goden's enemies, "
    "she has taken an early retirement to teach the young of "
    "her city how to equal her glorious deeds in warfare."
  );
}

