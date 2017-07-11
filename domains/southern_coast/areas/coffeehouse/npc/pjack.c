#include <lib.h>
#include <domains.h>
inherit LIB_PLAYER_BARKEEP;

static void create() {
  ::create();
  SetKeyName("bettsay");
  SetShort("Bettsay the Serving Wench");
  SetShopID("coffeehouse");
  SetId( ({ "bettsay", "wench" }) );
  SetAdjectives( ({ "serving" }) );
  SetRace("half-elf");
  SetGender("female");
  SetLocalCurrency("imperials");
  SetReligion("Eclat");
  SetMorality(400);
  SetLong(
    "Bettsay is a half-elf of some means. She tends the coffeehouse "
    "and keeps tabs on the locals who lounge here. Her friendly demeanor "
    "makes her a pleasant woman and one willing to sell a drink."
    );
  SetSkill("melee combat", 1, 1);
  SetLevel(15);
  SetBeverageDir(SOUTHERN_COAST_AREAS "coffeehouse/menu/");
}
