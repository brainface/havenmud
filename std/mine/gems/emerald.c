#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("emerald");
  SetValue(100);
  SetId( ({ "emerald", "gem" }) );
  SetShort("a small green gem");
  SetAdjectives( ({ "small", "green" }) );
  SetLong("This small green gem is an emerald.");
  SetMass(5);
  SetVendorType(VT_GEM|VT_TREASURE);
  SetDamagePoints(100);
}
