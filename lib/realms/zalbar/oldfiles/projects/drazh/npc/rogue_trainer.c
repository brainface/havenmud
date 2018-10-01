// Modified by Dahaka
// Aug 2004

#include <lib.h>
#include "../drazh.h"
#include <position.h>

inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("skredrak");
  SetId( ({"skredrak","trainer","skaven"}) );
  SetShort("Skredrak the Nightrunner");
  SetLong(
    "This hunched over skaven of medium height is covered in "
    "black silk strips all over his body. His red beady eyes "
    "peer out out the black strips to view his surroundings."
    );
  SetRace("skaven");
  SetTown("Drazh");
  RemoveClass();
  SetClass("rogue");
  SetLevel(42);
  SetMorality(-1250);
  SetGender("male");
  SetAction(5, ({
    "!speak I teach the ways of a nightrunner.",
    "!speak Have you come to study?",
    }) );
  SetCombatAction(10, ({
    "!disorient",
    "!disarm",
    }) );
  SetCurrency("roni", random(1000));
  SetLimit(1);
  SetPosition(POSITION_SITTING);
  AddTrainingSkills("bargaining");
  AddTrainingSkills("lockpicking");
  AddTrainingSkills("stealing");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("stealth");
  AddTrainingSkills("multi-weapon");
  SetInventory( ([
    V_OBJ + "hooded_robe"  : 
      "wear robe on torso and right leg and right arm and left arm and left leg",
    V_OBJ + "lpants"       : "wear pants",
    V_OBJ + "lvest"        : "wear vest",
    V_OBJ + "guard_knife"  : "wield knife",
    ]) );
}
