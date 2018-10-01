#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;

static void create()
{
  trainer::create();
  SetKeyName("drahcir");
  SetShort("Drahcir, the Gladiator");
  SetId( ({
    "gladiator", "nosferatu", "drahcir",
  }) );
  SetLong(
    "Drahcir is the gladiator champion of the Grymxorian "
    "Arena. He has fought every beast known to man or god, "
    "and many of those he tracked to their own lair. Now "
    "Drahcir trains would be fighters and barbarians in "
    "between bouts in the arena"
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("fighter");
  SetClass("barbarian");
  SetLevel(60);
  SetTown("Grymxoria");
  SetCurrency("bloodgems", 10000);
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
    G_OBJ + "nosf_axe" : "wield axe",
  ]) );
  AddTrainingSkills("melee attack");
  AddTrainingSkills("slash attack");
  AddTrainingSkills("projectile attack");
  AddTrainingSkills("projectile defense");
  AddTrainingSkills("melee defense");
  AddTrainingSkills("slash defense");
  AddTrainingSkills("stealth");
  AddTrainingSkills("blunt attack");
  AddTrainingSkills("hack attack");
  AddTrainingSkills("blunt defense");
  AddTrainingSkills("hack defense");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("multi-hand");
  SetFriends( ({ "lothar", "thundar", "guard", "citizen" }) );
}
