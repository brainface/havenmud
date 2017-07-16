#include <lib.h>
#include "../keryth.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("huram");
  SetShort("Huram, the Shopkeep");
  SetLong("Ever greedy, Huram stands ready to make profit by selling his "
          "wares and attempting to pay as little as possible for valuable "
          "items.");
  SetMorality(-75);
  SetRace("goden");
  SetClass("merchant");
  SetLevel(20);
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("senones");
  SetStorageRoom(K_ROOM + "/storage");
  SetMaxSingleItem(15);
  SetMaxItems(60);
  SetAction(5, ({ "!look", "!grin" }) );
}