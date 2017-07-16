#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();
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
    U_OBJ + "lala_loincloth" : "wear loincloth",
    ]) );
  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "hospital_store");
  SetMaxItems(65);
  SetVendorType(VT_HERB|VT_PLANT);
  SetMorality(0);
  SetCurrency("skins",123 + random(75) );
}
