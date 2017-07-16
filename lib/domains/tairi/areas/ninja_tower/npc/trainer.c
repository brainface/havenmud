// Coded by Zeratul
// 3-17-2000
// Ninja Teacher

#include <lib.h>
#include "../ninja.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("ninja");
  SetId( ({ "ninja", "trainer" }) );
  SetAdjectives( ({ "ninja", "trainer" }) );
  SetShort("the ninja trainer");
  SetLong(
     "This ninja warrior is from the valley lands of Tai-Ri. He is the "
     "one whom trains the ninjas who seek assistance in combat skills. "
  );
  SetGender("male");
  SetRace("human");
  SetReligion("Taisoka");
  SetTown("Tairi");
  SetLevel(40);
  SetInventory( ([
     N_OBJ + "shozoku" : "wear armour",
  ]) );
  SetMorality(70);
  SetFriends( ({
     "guard","ninja","old man"
  }) );
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  AddTrainingSkills("melee combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("stealth");
  AddTrainingSkills("stealing");
  AddTrainingSkills("lockpicking");
  AddTrainingSkills("natural magic");
  }
