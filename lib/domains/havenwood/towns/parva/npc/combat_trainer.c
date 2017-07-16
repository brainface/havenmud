#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("Rodrigo de Vivar");
  SetShort("Rodrigo de Vivar");
  SetId( ({ "rodrigo", "vivar", "trainer" }) );
  SetAdjectives( ({ "rodrigo", "de" }) );
  SetLong(
    "Rodrigo de Vivar is far and away the greatest trainer in martial skills "
    "ever to cross into Parva. His unrivalled knowledge of all things combat-"
    "related makes him a formidible foe indeed."
    );
  SetRace("human");
  SetGender("male");
  SetClass("cavalier");
  SetSkill("accuracy",1,2);
  SetSkill("parry",1,1);
  SetSkill("disarm",1,3);
  SetSkill("pierce combat",1,1);
  SetSkill("combat rage",1,3);
  SetSkill("melee combat",1,3);
  SetLevel(350);
  SetCurrency("oros", 500);
  SetInventory( ([
    PARVA_OBJ "rapier" : "wield rapier",
    ]) );
  SetCombatAction(15, ({
  	"!disarm",
  	}) );
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("cooking");
  SetTown("Parva");
}
