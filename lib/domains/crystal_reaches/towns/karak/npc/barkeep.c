// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_BARKEEP;

static void create() {
	barkeep::create();
  SetKeyName("zurth");
  SetId( ({ "zurth", "barkeep", "barkeeper", "orc"}) );
  SetShort("Zurth the Barkeep");
  SetLong(
    "Zurth was apparently the runt of his litter, standing at barely six "
    "feet in height, lacking the sheer bulk of the rest of his race. His "
    "dark red eyes gleam and his matted skin is well-groomed, suggesting "
    "that life as a bartender has worked well for him. Despite his reduced "
    "size is appears he would still be a reasonable opponent for beginning "
    "adventurers."
  );
  SetRace("orc");
  SetClass("fighter");
  SetGender("male");
  SetLevel(16);
  SetReligion("Saahagoth");
  SetMorality(-100);
  SetLocalCurrency("orcteef");
  SetInventory( ([
    KARAK_OBJ + "axe" : "wield axe",
  ]) );
  SetMenuItems( ([
    "orcish grog"       : KARAK_MENU + "grog",
    "dwarves head stew" : KARAK_MENU + "stew",
    "sprite wings"      : KARAK_MENU + "wings",
  ]) );

}
