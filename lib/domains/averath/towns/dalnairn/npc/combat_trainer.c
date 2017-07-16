#include <lib.h>
#include "../dalnairn.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("werir");
  SetShort("Werir, Master of Arms ");
  SetId( ({ "werir", "master of arms", "dalnairn_people", "master" }) );
  SetLong("Werir is a stocky dark dwarf with a shaven head and a long "
          "black braided beard.  He has followed Captain Jolich in "
          "may campaigns and has trained many of citizens of Dalnairn "
          "to defend themselves.  Werir will teach any dark-dwarf if "
          "<ask>ed.");
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("fighter");
  SetSkill("hack combat",1,1);
  SetSkill("combat rage",1,1);
  SetLevel(50);
  SetMorality(-500);
  SetCurrency("shards",random(300));
  SetInventory( ([
    DAL_OBJ + "hooked_axe" : "wield axe",
    DAL_OBJ + "guardarmour" : "wear armour",
    DAL_OBJ + "boots" : "wear boots",
    ]) );
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  SetTown("Dalnairn");
  }
