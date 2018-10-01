/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("iron");
  SetShort("a rusty iron ingot");
  SetId( ({ "iron", "ingot" }) );
  SetAdjectives( ({ "rusty","iron" }) );
  SetLong("A rough hewn block of pig iron, smelted just enough to get "
    "the dust out. Its surface is already rusting.");
  SetMass(15*3/2);
  SetValue(500*3);
  SetDamagePoints(1000);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

