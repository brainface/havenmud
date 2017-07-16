#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("lala");
  SetAdjectives( ({
    "attractive"
    }) );
  SetId( ({
    "lala"
    }) );
  SetShort("lala");
  SetLong("Lala is a human who decided to open a healing "
          "shop in Ungkh for the good of the primitives "
          "who live here.  She is very attractive.");
  SetRace("human");
  RemoveLanguage("Eltherian");
  SetLanguage("Uruk",100,1);
  SetClass("rogue");
  SetLevel(45);
  SetGender("female");
  SetInventory( ([
    U_OBJ + "gob_knife" : "wield knife",
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );
  SetLocalCurrency("skins");
   SetMenuItems( ([
    "root" : U_OBJ + "gornash_root",
    "yellow mushroom" : U_OBJ + "yellow_shroom",
    "green mushroom" : U_OBJ + "green_shroom",
    "red mushroom" : U_OBJ + "red_shroom",
    "orange mushroom" : U_OBJ + "blue_shroom",
    ]) );
  SetMorality(0);
  SetCurrency("skins",123 + random(75) );
}
