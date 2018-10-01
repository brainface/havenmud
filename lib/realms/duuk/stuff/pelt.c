#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pelt");
  SetShort("a pelt");
  SetLong("This is a pelt from a furry thing.");
  SetId( ({ "pelt" }) );
  SetValue(20);
  SetMass(10);
  SetVendorType(VT_FUR);
 }
