#include <lib.h>
#include <rounds.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("sparring");
  SetTrainingPointCost(10);
  SetSkills( ([
     ]) );
  SetStaminaCost(3);
  SetHelp("This tactic allows the skilled user to not harm "
          "his/her partner while in combat.");
 }

int eventStyle(object who, int level, mixed target) {
  object *weapons = who->GetWielded();
  if (arrayp(target)) target = target[0];

  who->eventPrint("You spar with " + (string)target->GetName() + ".");
  target->eventPrint(who->GetName() + " seems to pull " +
                     possessive(who) + " attack to lessen the damage.");
  if (random(100) > who->GetCombatStyleLevel("sparring")) {
      who->eventTrainCombatStyle("sparring", 25);
    }
  if (sizeof(weapons)) {
     return who->eventWeaponRound(target, weapons);
   }
  return who->eventMeleeRound(target);
 }
