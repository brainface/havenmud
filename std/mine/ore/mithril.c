/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mithril nugget");
  SetShort("a glowing mithril nugget");
  SetId( ({ "glowing", "nugget" }) );
  SetAdjectives( ({ "glowing","mithril" }) );
  SetLong("This ore glows with a force of magic undeniable. No "
    "rust or blemish stains its mirrory surface.");
  SetMass(15);
  SetValue(3500);
  SetDamagePoints(1000);
  SetMaterial( ({ "mithril" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

