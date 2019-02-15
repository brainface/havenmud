#include <lib.h>
inherit LIB_MULE_SELLER;

static void create() {
  ::create();
  SetKeyName("Galo");
  SetShort("Galo the Seller of Steeds");
  SetLong(
    "Alpacha is a strange elf. He sells mules to those in need of "
    "extra carrying capacity. <greet alpacha> to see the cost he "
    "would charge you."
    );
  SetRace("human");
  SetGender("male");
  SetId( ({ "galo", "seller" }) );
  SetAdjectives( ({ "steeds" }) );
  SetTown("Sanctum");
  SetCostModifier(1.0);
  SetClass("merchant");
  SetLevel(10);
  SetMorality(150);
  SetReligion("Kylin");
}

