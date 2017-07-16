// by Melchezidek
// Aug 2004

#include <lib.h>
#include "../drazh.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("azhak");
  SetId( ({"azhak","trainer","skaven"}) );
  SetAdjectives( ({"master","of","the","watch"}) );
  SetShort("Azhak, Master of the Watch");
  SetLong(
    "Azhak is a large dark furred battle scarred skaven. His "
    "long snout has a huge scare running across his face, making "
    "him a rather ugly sight to see. He has retired from combat "
    "to teach the young of this town the ways of survival. "
    );
  SetRace("skaven");
  SetTown("Drazh");
  RemoveClass();
  SetClass("fighter");
  SetLevel(40);
  SetMorality(-1000);
  SetGender("male");
  SetAction(5, ({
    "!speak I teach the ways of combat.",
    "!speak Have you come to study the way of the watchman?",
    "!speak All must train to grow strong.",
    }) );
  SetCombatAction(5, ({
    "!disarm",
    "!disorient",
    }) );
  SetCurrency("roni", random(450));
  AddTrainingSkills("slash combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("blunt combat");
  SetInventory( ([
    V_OBJ + "axe"        : "wield axe",
    V_OBJ + "scale_mail" : "wear armour",
    V_OBJ + "lpants"     : "wear pants",
    ]) );
 }