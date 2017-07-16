/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("silver nugget");
  SetShort("a dark silver nugget");
  SetId( ({ "silver", "nugget" }) );
  SetAdjectives( ({ "dark","silver" }) );
  SetLong("A blackish nugget of dark metal. Bits of silver gleam through "
    "a thin layer of oxidation.");
  SetMass(15);
  SetValue(1500);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

