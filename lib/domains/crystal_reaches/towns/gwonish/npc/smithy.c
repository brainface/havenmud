#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../gwonish.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("ravase");
  SetId( ({ "ravase", "smith" }) );
  SetAdjectives( ({ "swamp", "lizardman" }) );
  SetShort("Ravase the Smith of the Swamp");
  SetLong("Ravase is a large lizardman and appears to be very old. Despite "
         "his age he appears very agile and strong. He can teach young "
         "lizardmen the ways to repair and maintain weapons and armours."
         );
  SetRace("lizardman");
  SetTown("Gwonish");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(50);
  SetMorality(-100);
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");

}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
