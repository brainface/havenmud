#include <lib.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("commodus");
  SetShort("Commodus Maximus, Master of Swords");
  SetId( ({ "commodus", "maximus", "master", "swordsmaster" }) );
  SetAdjectives( ({ "commodus", "master", "swords", "sword" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetTown("Sanctum");
  SetLanguage("Imperial", 100, 1);
  SetTrainingSkills( ({ "slash combat", "slash combat" }) );
  SetGender("male");
  SetLevel(12);
  SetCurrency("imperials", 20);
  SetMorality(-50);
  SetLong("Commodus is the SwordsMaster of the Sanctum Colosseum. "
          "He excels in all forms of slash weaponry, and is willing "
          "to train any person dedicated and willing to learn.");
  SetLimit(1);
}
