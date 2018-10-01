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
  SetShort("Vorn the Old Barian Trainer");
  SetId( ({"vorn","trainer","man","barian trainer","vorn the barian trainer"}) );
  SetAdjectives( ({"old","skilled","agile"}) );
  SetLong("Vorn was a very agile hunter when he was younger, but "
          "due to his age, he is limited to teaching the knowledge "
          "he acquired throughout the years."
  );
  SetSkill("pierce attack", 1, 1);
  SetSkill("pierce defense", 1, 1);
  SetSkill("melee attack", 2, 1);
  SetSkill("melee defense", 2, 1);
  SetLevel(45);
  SetRace("human");
  SetMorality(-50);
  RemoveLanguage("Enlan");
  SetTown("Baria");
  SetLanguage("Barian", 100, 1);
  SetClass("hunter");
  SetGender("male");
  SetCurrency( ([
     "chits" : 500 + random(500),
  ]) );
  SetFriends( ({"Brun"}) );

  AddTrainingSkills("projectile attack");
  AddTrainingSkills("melee attack");
  AddTrainingSkills("slash attack");
  AddTrainingSkills("hack attack");
  AddTrainingSkills("pierce attack");
  AddTrainingSkills("knife attack");
  AddTrainingSkills("blunt attack");
  AddTrainingSkills("pole attack");
  AddTrainingSkills("slash defense");
  AddTrainingSkills("blunt defense");
  AddTrainingSkills("pole defense");
  AddTrainingSkills("pierce defense");
  AddTrainingSkills("hack defense");
  AddTrainingSkills("projectile defense");
  AddTrainingSkills("melee defense");
  AddTrainingSkills("knife defense");
  SetInventory( ([
     BARIA_OBJ + "bronze_spear" : "wield spear",
     BARIA_OBJ + "loincloth" : "wear loincloth",
     BARIA_OBJ + "vest" : "wear vest",
  ]) );
}
