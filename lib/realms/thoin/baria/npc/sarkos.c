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
  SetKeyName("sarkos");
  SetShort("Sarkos the Feeble");
  SetId( ({"sarkos","man","vorn the feeble"}) );
  SetAdjectives( ({"old","feeble"}) );
  SetLong("Sarkos in his youth was a great hunter and learned how "
          "to not only fight but how to repair things as well. "
          "Though now due to his age he is limited to teaching the knowledge "
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
  SetClass("valkyr");
  SetGender("male");
  SetCurrency( ([
     "chits" : 500 + random(500),
  ]) );
  SetFriends( ({"Vorn"}) );
  AddTrainingSkills("stealth");
  AddTrainingSkills("leather working");
  AddTrainingSkills("metal working");
  AddTrainingSkills("fishing");
  AddTrainingSkills("farming");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("textile working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("weapon smithing");
  SetInventory( ([
     BARIA_OBJ + "bronze_spear" : "wield spear",
     BARIA_OBJ + "loincloth" : "wear loincloth",
     BARIA_OBJ + "vest" : "wear vest",
  ]) );
}
