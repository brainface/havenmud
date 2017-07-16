//  Jewelry Shop Vendor for Marketplace
//  Alessandra 2009

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  
  SetKeyName("Nardus");
  SetShort("nardus the Jeweler");
  SetId( ({"nardus", "jeweler", "man", "dark-elf"}) );
  SetAdjectives( ({"shrewd", "slight"}) );
  SetLong(
     "With his gleaming black hair held back with a small ribbon and beady "
     "eyes peering from behind his dark brows, Nardus looks like a shrewd "
     "man. He owns this jewelry shop, and is known for his shady business "
     "dealings and nefarious clientele."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(30);
  SetVendorType(VT_TREASURE);
  SetLocalCurrency("roni");
  SetStorageRoom(MAL_ROOMS3 + "jewel_stor");

}
