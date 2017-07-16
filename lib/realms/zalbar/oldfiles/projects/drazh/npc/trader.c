// Modified by Zalbar
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include "../drazh.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("snee");
  SetId( ({"snee","smith","skaven"}) );
  SetShort("Snee the Trader");
  SetLong(
     "Snee is a large and strong skaven with brown fur. His large frame comes from "
     "countless days spent working in the forge that sits in the corner "
     "of the smithy. His face is covered with a black ash, giving a short "
     "smirk to those around him. "
     );
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetLevel(15);
  SetMorality(-1300);
  SetVendorType(VT_ALL);
  SetLocalCurrency("roni");
  SetStorageRoom(V_ROOM + "misc/str_trader");
}
