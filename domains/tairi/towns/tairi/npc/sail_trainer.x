#include <lib.h>
inherit LIB_TRAINER;
#include "../tairi.h"

static void create() {
  trainer::create();
  SetKeyName("Thorn");
  SetShort("Thorn, a Wako Captain");
  SetId( ({ "thorn", "wako", "captain"}) );
  SetClass("sailor");
  SetTown("Tairi");
  SetLevel(40);
  AddTrainingSkills("sailing");
  AddTrainingSkills("navigation");
  AddTrainingSkills("bargaining");
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Tai");
  SetMorality(-200);
  SetLong("Thorn is a wild-eyed Wako, a Tai coastal raider. Most of "
          "the citizens of Tairi are quite content to live in isolated "
          "splendor, but for the very few willing to explore the seas "
          "Thorn serves as a trainer.");
  SetInventory( ([
    ]) );
}
