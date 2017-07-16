#include <lib.h>
#include "../dalnairn.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("gilthic");
  SetShort("Gilthic the Underhand");
  SetId( ({ "gilthic", "underhand", "dalnairn_people"}) );
  SetAdjectives( ({ "gilthic" }) );
  SetLong("Gilthic is a small and lean dark-dwarf.  He is a known "
    "apprentice of Morven.  Gilthic will teach anyone willing "
    "to learn skills, which will be useful to those that travel "
    "outside of Dalnairn."
    );
  SetRace("dark-dwarf");
  SetClass("rogue");
  SetSkill("melee combat",1,1);
  SetSkill("cloth armour",1,2);
  SetSkill("leather armour", 1,2);
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  SetSkill("parry",1,2);

  SetGender("male");
  SetTown("Dalnairn");
  SetLevel(25);
  AddTrainingSkill("bargaining");
  AddTrainingSkills("stealing");
  AddTrainingSkills("stealth");
  AddTrainingSkills("cooking");
  AddTrainingSkills("lockpicking");

  SetInventory( ([
    DAL_OBJ "pants" : "wear pants",
    DAL_OBJ "shirt" : "wear shirt",
    DAL_OBJ "boots" : "wear boots",
    ]) );
  SetMorality(-1000);
  SetCurrency("shards", 200);
}
