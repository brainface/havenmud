/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("copper nugget");
  SetShort("a greenish copper nugget");
  SetId( ({ "copper", "nugget" }) );
  SetAdjectives( ({ "greenish","copper" }) );
  SetLong("A bit of soft copper ore, gone green with oxidation.");
  SetMass(15);
  SetValue(200);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }

