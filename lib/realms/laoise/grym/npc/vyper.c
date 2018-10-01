#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;

static void create()
{
  trainer::create();
  SetKeyName("vyper");
  SetShort("Vyper, the Mistress of Saahagoth");
  SetId( ({ "mistress of saahagoth", "nosferatu", "mistress",
    "vyper", }) );
  SetLong(
    "Vyper is the Mistress of the Initiates of Saahagoth. "
    "It is her job to see that the faithful recieve the "
    "training they need."
  );
  SetRace("nosferatu");
  SetGender("female");
  SetClass("cleric");
  SetLevel(50);
  SetTown("Grymxoria");
  SetReligion("Saahagoth","Saahagoth");
  SetCurrency("bloodgems", (random(3000) + 6000));
  SetInventory( ([
    G_OBJ + "nosf_mace" : "wield mace",
  ]) );
  SetSkill("blunt attack", 150, 0);
  SetSkill("enchantment", 150, 0);
  SetSkill("necromancy", 150, 0);
  SetSkill("pole defense", 102, 2);
  SetSkill("healing", 102, 2);
  SetSkill("blunt defense", 102, 2);
  SetSpellBook( ([
    ]) );
  AddTrainingSkills("faith");
  AddTrainingSkills("necromancy");
  AddTrainingSkills("healing");
  AddTrainingSkills("enchantment");
}
