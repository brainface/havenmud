
#include <lib.h>
#include "../durgoroth.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("ereshk");
  SetShort("Ereshk the Masterful");
  SetId( ({"ereshk", "master"}) );
  SetAdjectives( ({"masterful"}) );
  SetLong("As the largest and most powerful daemon to remain"
          " in the city, Ereshk is the decider of who lives"
          " and dies. His fearsome appearance is magnified by"
          " his reputation as one of the most gruesome and"
          " vicious beings ever to walk upon Kailie. Anyone"
          " wishing to increase their skill base should"
          " speak to him.");
  SetTown("Durgoroth");
  SetRace("daemon"); 
  SetMorality(-2000);
  SetGender("male");
  RemoveClass();
  SetClass("horror");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("natural working");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("leather working");  
  AddTrainingSkills("metal working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("weapon smithing");
  SetLevel(250);
  SetCombatAction(10, ({
     "!scream",
     "!disarm",
     "!disorient",
     "!scream",
     }) );
  SetInventory( ([
     DURG_OBJ "fighter_helmet" : "wear helmet",
     DURG_OBJ "fighter_plate"  : "wear suit",
     DURG_OBJ "horseshoe"      : "wear 1st horseshoe on left hoof",
     DURG_OBJ "horseshoe2"     : "wear 1st horseshoe on right hoof",
     DURG_OBJ "duster"         : "wield 1st duster",
     DURG_OBJ "duster2"        : "wield 1st duster",
     ]) );
  SetCurrency("crystals", 5000);

}
