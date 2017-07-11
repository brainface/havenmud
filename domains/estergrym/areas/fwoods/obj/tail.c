
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tail");
  SetShort("a fluffy tail");
  SetId( ({"tail"}) );
  SetAdjectives("fluffy");
  SetLong("This is a fluffy rabbit's tail.");
  SetValue(500);
  SetMass(10);
  SetVendorType(VT_FUR);
 }