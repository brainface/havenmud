#include <lib.h>
#include "../haven.h"
#include <vendor_types.h>
inherit LIB_OLD_VENDOR;

static void create() {
  ::create();
  SetKeyName("taylor");
  SetId( ({ "taylor" }) );
  SetShort("Taylor, the shopkeep");
  SetLong("Taylor is a reputable shopkeep that has been in Haven "
          "since before most of the oldest people in town were born. "
          "His ethics and style are above question.");
  SetMorality(100);
  SetRace("elf");
  SetClass("merchant");
  SetLevel(50);
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("imperials");
  SetStorageRoom(H_ROOM "storage_rooms/str_sh");
  SetMaxSingleItem(12);
  SetMaxItems(500);
}

