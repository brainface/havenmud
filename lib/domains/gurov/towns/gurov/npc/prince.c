#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetTown("Gurov");
  SetShort("Prince Boris of Gurov");
  SetId( ({ "prince", "boris" }) );
  SetAdjectives( ({ "prince", "gurov" }) );
  SetFriends( ({ "guard" }) );
  SetKeyName("boris");
  SetLong(
    "Boris Prince of Gurov is a heavy man with a regal bearing. "
    "His scarred cheeks give lie to the fact that as a young man "
    "the Prince served in the guard protecting the previous Prince. "
    "His swagger is one that suggests he is one to be reckoned with."
    );
  SetAction(3, ({
    "!speak You could ask me to grant you citizenship if you desired.",
  }) );
  SetLimit(1);
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("cavalier");
  SetLevel(60);
  SetInventory( ([
    STD_PIERCE "fencing_sword" : "wield sword",
    ]) );
  SetCombatAction(5, ({
  	"disarm"
  	}) );
  SetCurrency("rubles",10 + random(60));
  SetMorality(500);
  SetGender("male");
  SetLocalCurrency("rubles");
  SetTax(100);
}
