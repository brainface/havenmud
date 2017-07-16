#include <lib.h>
#include "../karak.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("grond");
  SetShort("Grond the shopkeep");
  SetLong("A dirty looking Orc wearing the apron of a blacksmith.");
  SetRace("orc");
  SetClass("rogue");
  SetLevel(25 + random (7));
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("orcteef");
  SetStorageRoom(K_ROOM + "/junk");

}
