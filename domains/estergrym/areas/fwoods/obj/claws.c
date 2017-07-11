
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("claws");
  SetShort("a set of severed claws");
  SetId( ({"claws","set"}) );
  SetAdjectives( ({ "long", "severed" }) );
  SetLong("These long claws are still covered in dried blood.");
  SetValue(1000);
  SetMass(10);
  SetVendorType(VT_TREASURE);
 }
