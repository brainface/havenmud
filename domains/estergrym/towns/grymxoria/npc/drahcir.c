#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;

static void create()
{
  trainer::create();
  SetKeyName("drahcir");
  SetShort("drahcir, the Gladiator");
  SetId( ({ "gladiator", "nosferatu", "drahcir", }) );
  SetLong(
    "Drahcir is the gladiator champion of the Grymxorian "
    "Arena. He has fought every beast known to man or god, "
    "and many of those he tracked to their own lair.  Now "
    "Drahcir trains would be fighters in between bouts in "
    "the arena"
  );
  SetRace("nosferatu");
  SetTown("Grymxoria");
  SetMorality(-1000);
  SetFriends( ({ "lothar", "thundar", "guard", "citizen" })  );
  SetGender("male");
  SetClass("fighter");
  SetLevel(60);
  SetCurrency("bloodgems", 10000);
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
    G_OBJ + "nosf_axe" : "wield axe",
  ]) );
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("pole combat");
}
