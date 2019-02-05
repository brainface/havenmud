#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../gwonish.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("sabaksil");
  SetId( ({ "sabaksil", "slink" }) );
  SetAdjectives( ({ "swamp", "lizardman" }) );
  SetShort("Sabaksil the Slink of the Swamp");
  SetLong("This skulking lizardwoman is slender to the point of being "
    "snakelike. Her scales are striped black and jagged browns, making "
    "her hard to distinguish among the bog and reeds of the marsh. She "
    "furtively glances at those walking by, as if she had some secretive "
    "knowledge she wished to impart."
  );
  SetRace("lizardman");
  SetGender("female");
  SetTown("Gwonish");
  SetClass("rogue");
  SetLevel(50);
  SetMorality(-100);
  // don't like giving bargaining to crazy lizard folk.
  // but no bargaining = worthlessly broke
  AddTrainingSkills("bargaining");
  AddTrainingSkills("cooking");
  AddTrainingSkills("fishing");
  AddTrainingSkills("navigation");
  AddTrainingSkills("sailing");
  AddTrainingSkills("skinning");
  AddTrainingSkills("stealth");
  AddTrainingSkills("swimming");
}

int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
  return ::eventDie(killer);
}

