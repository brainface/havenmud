/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("gold nugget");
  SetShort("a shiny gold nugget");
  SetId( ({ "gold", "nugget" }) );
  SetAdjectives( ({ "shiny","gold" }) );
  SetLong("Shiny, soft, and delicious, this nugget of yellowish "
    "gold sparkles in the light, promising riches.");
  SetMass(15);
  SetValue(2500);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

