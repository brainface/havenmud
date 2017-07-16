/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("gold ingot");
  SetShort("a glimmering gold ingot");
  SetId( ({ "gold", "ingot" }) );
  SetAdjectives( ({ "glimmering","gold" }) );
  SetLong("A perfectly formed oblong of pure gold, shimmering and "
    "shining in the light.");
  SetMass(15*3/2);
  SetValue(2500*3);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

