#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("talomus");
  SetShort("Talomus the Fast Talker");
  SetRace("human");
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetId( ({ "talomus", "talker" }) );
  SetAdjectives( ({ "fast" }) );
  SetGender("male");
  SetTown("Sanctum");
  SetLong("Talomus drives a bargain.  A hard bargain.  He's "
          "known as one of the few people in the world that "
          "can get fair treatment with Tylus! His short brown "
          "hair and impish smile let all who look at him know "
          "that his knowledge can be important.");
  SetTrainingSkills( ({
    "bargaining", 
    "stealth", 
    "stealing", 
    "lockpicking",
    "farming", 
    "projectile combat",
    }) );
  SetLevel(15);
  SetLimit(1);
  SetInventory( ([
    ROME_OBJ "toga" : "wear toga",
  ]) ) ;
}
