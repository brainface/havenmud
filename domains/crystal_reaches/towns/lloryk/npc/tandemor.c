#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("Tandemor Vinyok");
  SetShort("Tandemor Vinyok, Trainer of Magical Skills");
  SetId( ({ "tandemor", "vinyok", "trainer" }) );
  SetLong("Tandemor is an aspiring Evoker earning his keep in the "
          "Shire of Lloryk. In that capacity he will "
          "train others in whatever skills he knows");
  SetRace("halfling");
  SetFriends( ({ "feckel" }) );
  SetGender("male");
  //RemoveClass();
  SetClass("evoker");
  SetLevel(50);
  SetMorality(100);
  SetCurrency("imperials",random(300)+1);
  SetInventory( ([
    LLORYK + "obj/mrobes" : "wear robes",
    ]) );
  AddTrainingSkills("bargaining");
  AddTrainingSkills("textile working");
  AddTrainingSkills("mithril working");
  SetSpellBook( ([
    "mesmer barrier" : 100,
    "disintegrate"   : 100,
    "bolt"           : 100,
    ]) );
  SetCombatAction(85, ({
    "!cast mesmer barrier",
    "!cast bolt",
    "!cast disintegrate",
    }) );
  SetTown("Lloryk");
}
