/*  A local shopkeep */
#include <lib.h>
#include <vendor_types.h>
#include "../goblins.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("garbuk");
  SetId( ({ "garbuk", "shopkeep" }) );
  SetShort("Garbuk the Swindler");
  SetLong("Garbuk the Swindler is the local tradesman. He is known "
          "far and wide as the brightest goblin tradesman ever. ");
  SetRace("goblin");
  SetClass("merchant");
  SetLocalCurrency("rounds");
  SetVendorType(VT_ALL);
  SetLevel(1);
  SetStorageRoom(GOBLIN_TENT + "shop_storage");
  SetGender("male");
  SetMaxSingleItem(10);
  }
