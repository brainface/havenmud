#include <lib.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("brutus");
  SetId( ({ "brutus", "brawler" }) );
  SetShort("Brutus the Brawler");
  SetLong(
    "Brutus is the master of many combat styles.  If asked, "
    "he might even be willing to teach some of them."
  );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetClass("fighter");
  SetLevel(15);
  SetGender("male");
  SetTown("all");
  SetReligion("agnostic");
  SetTrainingSkills( ({
    "brawling", "melee combat",
    }) );
}
