//  Portia  10-23-98
//  A General storekeeper.
//  Updated by Alessandra 2009

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  
  SetKeyName("tom");
  SetShort("tom the Storekeeper");
  SetId( ({"tom", "storekeeper", "dark-elf", "man", "vendor"}) );
  SetAdjectives( ({"slight", "attractive"}) );
  SetLong(
     "Tom is a slight man, for a dark-elf, but is considered one of the "
     "most attractive men in Malveillant. His appearance is meticulous, as "
     "is his shop, and his deep black eyes betray his high intelligence."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(20);
  SetVendorType(VT_ALL);
  SetLocalCurrency("roni");
  SetStorageRoom(MAL_ROOMS3 + "gen_stor");

}
