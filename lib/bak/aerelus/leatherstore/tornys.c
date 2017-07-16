#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "store.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("tornys");
  SetId( ({ "tornys", "dealer" }) );
  SetShort("Tornys the leather dealer");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Tornys is a small, stout man with a huge grey moustache. He collects and "
    "sells leather items, and can usually be found in his store near Haven "
    "town. His products are known to be very tough, but flexible enough "
    "to cause little discomfort."    
  );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  AddCurrency("imperials", random(100));
  SetMorality(10);
  SetClass("merchant");
  SetLevel(30);  
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR);  
}
