#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "store.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("urk");
  SetId( ({ "", "armoursmith" }) );
  SetShort("Urk the hideous armoursmith");
  SetAdjectives( ({ "hideous" }) );
  SetLong(
    "Urk is covered in numerous scars and is missing half his left ear. He is by "
    "far one of the ugliest orcs ever. He is covered in soot which only makes his "
    "foul odor worst. It is remarkable he can do any business with the way he smells."
  );
  SetRace("orc");
  SetGender("male");
  SetBaseLanguage("Uruk");
  SetLocalCurrency("orcteef");
  AddCurrency("orcteef", random(100));
  SetMorality(-100);
  SetClass("merchant");
  SetLevel(50);  
  SetStat("charisma", 1);
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR);  
}
