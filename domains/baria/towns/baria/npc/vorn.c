//
//  a trainer for baria
//    kyla 2-98
//  Modified by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("vorn");
  SetId( ({"vorn","trainer","man","barian trainer","vorn the barian trainer"}) );
  SetAdjectives( ({"old","skilled","agile"}) );
  SetShort("Vorn the Old Barian Trainer");
  SetLong("Vorn was a very agile hunter when he was younger, but "
          "due to his age, he is limited to teaching the knowledge "
          "he acquired throughout the years."
  				);
  
  
  SetRace("human");  
  SetGender("male");
  SetMorality(-50);
  RemoveLanguage("Enlan");
  SetTown("Baria");
  SetLanguage("Barian", 100, 1);
  SetClass("rogue");
  SetSkill("pierce combat",1,2);
  SetLevel(45);
  SetCurrency( ([
     "chits" : 20 + random(25),
 		 ]) );
  SetFriends( ({"Brun"}) );
  AddTrainingSkills("stealth");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("slash combat");  
  AddTrainingSkills("hack combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("leather working");
  AddTrainingSkills("metal working");
  AddTrainingSkills("fishing");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("textile working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("cooking");
  SetInventory( ([
     BARIA_OBJ + "bronze_spear" : "wield spear",
     BARIA_OBJ + "loincloth" : "wear loincloth",
     BARIA_OBJ + "vest" : "wear vest",
  ]) );
}


