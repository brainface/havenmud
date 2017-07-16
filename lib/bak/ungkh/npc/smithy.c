#include <lib.h>
#include <std.h>
#include "../ungkh.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("sorj");
  SetShort("Sorj the Smith");
  SetId( ({ "sorj", "smith" }) );
  SetAdjectives( ({ "ogre" }) );
  SetRace("ogre");
   RemoveLanguage("Shangtai");
   SetLanguage("Uruk",100,1);
  SetTown("Ungkh");
  SetClass("fighter");
  SetLevel(50);
  SetMorality(-100);
  SetGender("male");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("metal working");
 SetLong("Sorj is a very large orge and appears to be young. He is covered "
         "in many scars and has bulging muscles. He would teach a young "
         "citizen how to repair and maintain armour and weapons if asked."
         );
}

