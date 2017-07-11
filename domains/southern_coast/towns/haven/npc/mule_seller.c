#include <lib.h>
inherit LIB_MULE_SELLER;

static void create() {
  ::create();
  SetKeyName("Alpacha");
  SetShort("Alpacha the Seller of Mules");
  SetLong(
    "Alpacha is a strange elf. He sells mules to those in need of "
    "extra carrying capacity. <greet alpacha> to see the cost he "
    "would charge you."
    );
  SetRace("elf");
  SetGender("male");
  SetId( ({ "alpacha", "seller" }) );
  SetAdjectives( ({ "mule" }) );
  SetTown("Haven");
  SetCostModifier(1.0);
  SetClass("merchant");
  SetLevel(10);
  SetMorality(150);
  SetReligion("Kylin");
}