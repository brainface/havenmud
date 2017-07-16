/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("iron nugget");
  SetShort("a rusty iron nugget");
  SetId( ({ "iron", "nugget" }) );
  SetAdjectives( ({ "rusty","iron" }) );
  SetLong("A chunk of ferrous ore, red and jagged with the promise "
    "of lockjaw.");
  SetMass(15);
  SetValue(500);
  SetDamagePoints(1000);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

