/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mithril");
  SetShort("a mesmerizing mithril ingot");
  SetId( ({ "mithril", "ingot" }) );
  SetAdjectives( ({ "mithril","mesmerizing" }) );
  SetLong("A perfect reflection stares back at you from the mirrory surface "
    "this hexagonal ingot, its form seeming to resonate with some strange "
    "metalline magic.");
  SetMass(15*3/2);
  SetValue(3500*3);
  SetDamagePoints(800);
  SetMaterial( ({ "mithril" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

direct_spin_str_from_obj() {
  return 1;
}
