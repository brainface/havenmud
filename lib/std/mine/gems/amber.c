/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("amber");
  SetShort("a glossy amber");
  SetId( ({ "amber", "gem" }) );
  SetAdjectives( ({ "glossy" }) );
  SetLong("This is a amber of decent quality. It is somewhat hard and "
  				"cut in a fine manner as to bring out its striking color. "
  				"This gem glows with a life of its own."
  				);
  SetMass(5);
  SetValue(500);
  SetDamagePoints(800);
  SetMaterial( ({ "natural" }) );
//  SetVendorType(VT_TREASURE);
  SetVendorType(VT_GEM|VT_TREASURE);
  SetLootType(LOOT_MINING);
  SetLootFrequency(LOOT_RARE);
  }


