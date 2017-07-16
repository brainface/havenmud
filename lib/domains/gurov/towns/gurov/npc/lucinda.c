#include <lib.h>
#include "../gurov.h"
inherit LIB_PLAYER_BARKEEP;

static void create() {
  ::create();
  SetKeyName("lucinda");
  SetShort("Lucinda, the Server at the Nubile Noble");
  SetShopID("gurov_inn2");
  SetId( ({ "lucinda", "server" }) );
  SetAdjectives( ({ "server" }) );
  SetRace("human");
  SetGender("female");
  SetLocalCurrency("rubles");
  SetMorality(100);
  SetLong(
    "Lucinda is a woman of some means. She tends the Nubile Noble "
    "and keeps tabs on the locals who lounge here. Her friendly demeanor "
    "makes her a pleasant woman and one willing to sell a way to relax."
    );
  SetClass("rogue");
  SetLevel(15);
  SetBaseLanguage("Gurovian");
  SetBeverageDir(GUROV_OBJ "inn2/");
}
