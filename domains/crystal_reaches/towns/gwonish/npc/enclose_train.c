// torak 10/27/12
#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../gwonish.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Ssiov");
  SetId( ({ "Ssiov", "lurker", "lizardman" }) );
  SetAdjectives( ({ "lurker", "lizardman" }) );
  SetShort("Ssiov the Lurker");
  SetLong("The Lurker, Ssiov, is built well "
    "for the hunts of the swamp.  His snout "
    "is more robust and his nostrils larger "
    "than most other lizardmen."
  );
  SetRace("lizardman");
  SetGender("male");
  SetTown("Gwonish");
  SetClass("fighter");
  SetLevel(120);
  SetMorality(-300);

  SetInventory( ([
    GWONISH_OBJ "serrated" : "wield sword",
    STD_CLOTHING "body/loin" : "wear loincloth",
    ]) );

  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("metal working");
}

int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
