#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("shiela");
  SetId( ({ "shiela", "shopkeep", "averath_person" }) );
  SetShort("Shiela, the local shopkeep");
  SetLong(
    "Shiela is the owner of the trading post here in town. "
    "She will gladly trade most any items for ducats."
  	);
        
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Avera");
  SetLocalCurrency("ducats");
  
  SetMorality(750);
  SetClass("merchant");
  SetLevel(15);
  AddCurrency("ducats", random(100)+5);
  
  SetStorageRoom(AVERATH_ROOM "storage/store_store");  
  SetProperty("no bump", 1);
  SetLocalCurrency("ducats");
  SetVendorType(VT_ALL);
  SetMaxItems(150);
  SetMaxSingleItem(20);
}
