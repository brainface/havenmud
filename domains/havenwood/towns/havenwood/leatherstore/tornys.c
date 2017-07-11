#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "store.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Kallin the Tanner");
  SetId( ({ "kallin", "tanner" }) );
  SetShort("Kallin the Havenwood Tanner");
  SetAdjectives( ({ "havenwood" }) );
  SetLong(
    "Kallin is a well developed wild-elf that spends most of her time "
    "ranging in the wood collecting hides. When she's in the tannery though "
    "she is willing to buy skins collected by others and also willing to "
    "sell the fruits of her work."
  );
  SetRace("wild-elf");
  SetGender("female");
  SetLocalCurrency("imperials");
  SetClass("ranger");
  SetSkill("bargaining", 1, 3);
  SetLevel(30);  
  AddCurrency("imperials", random(100) + 1);
  SetMorality(10);
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);
  SetLimit(1);
  SetVendorType(VT_ARMOUR|VT_FUR);  
}
