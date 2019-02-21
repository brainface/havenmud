// mahkefel 2019
// a universal riding trainer
#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("caius");
  SetShort("Caius the Campaigner");
  SetId( ({ "caius" }) );
  //SetAdjectives( ({ "vesta the" }) );
  SetLong(
    "A lean half-elf, hair hoary with age, Caius commanded the cavalry of "
    "the Sanctum Legion decades ago--and holds some notoriety as the only "
    "half-elf allowed such rank. Long-retired, and with his elven half "
    "causing him to outlive the rest of his cohort, he now teaches aspiring "
    "riders to pass the time."
  );
  SetRace("half-elf");
  SetBaseLanguage("Imperial");
  SetGender("male");
  SetLocalCurrency("imperials");
  SetClass("cavalier");
  SetMorality(0);
  SetLevel(35);
  SetLimit(1);
  SetTown("all");
  SetTrainingSkills( ({ "riding", "slash combat", "pole combat" }) ); 
}

