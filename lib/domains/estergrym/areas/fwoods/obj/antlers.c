
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("antlers");
  SetShort("a rack of antlers");
  SetId( ({"antlers","rack"}) );
  SetLong("This is a twelve point set of antlers from a large stag.");
  SetValue(700);
  SetMass(10);
  SetVendorType(VT_TREASURE);
 }