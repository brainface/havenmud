#include <lib.h>
#include "../underland.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("hanna");
  SetRace("gnome");
  SetGender("female");
  SetShort("Hanna the Shopkeep");
  SetId( ({ "gnome", "hanna", "shopkeep", }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Hanna is the local shopkeep. Her wares are few and rather drab, but "
    "she is known for fantastic pricing. Those interested in trading with "
    "her should <greet> her."
    );
  SetClass("merchant");
  SetLevel(6);
  SetStorageRoom(UNDER_ROOM "shop_str");
  SetVendorType(VT_ALL);
  SetMaxSingleItem(50);
  SetMaxItems(1000);
}
