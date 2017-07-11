// Karak Rewrite
// NPC from leatherstore
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../karak.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Gurk");
  SetId( ({ "gurk", "dealer" }) );
  SetShort("Gurk the leather dealer");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Gurk is a stout orc with a huge scar across his nose. He collects and "
    "sells leather items, and can usually be found in his store in Karak "
    "Varn. His products are known to be very tough, but flexible enough "
    "to cause little discomfort."    
  );
  SetRace("orc");
  SetGender("male");
  SetClass("merchant");
  SetLevel(30);  
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-50);
  SetLocalCurrency("orcteef");
  AddCurrency("orcteef", random(100));
  SetStorageRoom(KARAK_ROOM + "str_arm2");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR);  
}
