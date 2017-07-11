#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("golden statue");
  SetMass(1000);
  SetShort("a golden statue of a falcon");
  SetId( ({ "falcon", "statue" }) );
  SetClass(5);
  SetAdjectives( ({ "golden", "statue", "of", "falcon" }) );
  SetLong(
    "This statue stands three feet tall and appears to be quite valuable. "
    "The representation of a falcon is quite distinct."
    );
  SetValue(500000);
  SetVendorType(VT_TREASURE);
}