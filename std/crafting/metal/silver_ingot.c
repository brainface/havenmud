/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("silver ingot");
  SetShort("a mirrorlike silver ingot");
  SetId( ({ "silver", "ingot" }) );
  SetAdjectives( ({ "mirrorlike","silver" }) );
  SetLong("A gleaming oblong ingot of silvery metal. You can see your face "
    "staring back at you in the shining surface.");
  SetMass(15*3/2);
  SetValue(1500*3);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

