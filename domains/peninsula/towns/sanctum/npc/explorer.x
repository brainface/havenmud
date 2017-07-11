#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("doran");
  SetShort("Doran the Explorer");
  SetId( ({ "doran", "explorer" }) );
  SetGender("male");
  SetAdjectives( ({ "explorer" }) );
  SetRace("human");
  SetClass("merchant");
  SetLevel(1);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Doran the Explorer has travelled over most of the "
          "known world.  One thing he stresses to all of his "
          "customers is that flailing around in the darkness "
          "of the world at night is not a pleasant experience.");
  SetMenuItems( ([
    "torch" : STD_LIGHT "torch",
    "worm"  : STD_FISH "worm",
    "parchment" : STD_OBJ "parchment",

    ]) );
  SetLocalCurrency("imperials");
  SetLimit(1);
  SetInventory( ([
    ROME_OBJ "toga" : "wear toga",
    STD_OBJ "light/torch" : "wield torch",

  ]));
  SetFirstCommands( ({
    "light my torch",
  }) );
}
