/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tin nugget");
  SetShort("a crystalline tin nugget");
  SetId( ({ "tin", "nugget" }) );
  SetAdjectives( ({ "crystalline","copper" }) );
  SetLong("A bit of quartz-like tin ore, glimmering faintly.");
  SetMass(15);
  SetValue(400);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

