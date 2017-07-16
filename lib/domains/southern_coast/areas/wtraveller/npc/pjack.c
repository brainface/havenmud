#include <lib.h>
inherit LIB_PLAYER_BARKEEP;

static void create() {
  ::create();
  SetKeyName("jack");
  SetShort("Old Jack the Bartender");
  SetShopID("wtraveller");
  SetId( ({ "jack", "bartender" }) );
  SetAdjectives( ({ "old" }) );
  SetRace("half-elf");
  SetGender("male");
  SetLocalCurrency("imperials");
  SetReligion("Soirin");
  SetMorality(-400);
  SetLong(
    "Old Jack is a half-elf of some means. He tends bar and keeps "
    "tabs on the locals who drink here. His stuffy demeanor makes him "
    "an unpleasant fellow, but still one willing to sell a drink."
    );
  SetClass("fighter");
  SetSkill("melee combat", 1, 1);
  SetLevel(15);
}
