#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "store.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Temu");
  SetId( ({ "temu", "dealer" }) );
  SetShort("Temu the leather dealer");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Temu is a small, hairy goblin. He collects and "
    "sells leather items, and can usually be found in his tent in Kresh. "
    "His products are known to be very tough, but flexible enough "
    "to cause little discomfort."    
  );
  SetRace("goblin");
  SetGender("male");
  SetLocalCurrency("rounds");
  SetMorality(-10);
  SetClass("merchant");
  SetLevel(30); 
  AddCurrency("rounds", random(100)); 
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR);  
}
