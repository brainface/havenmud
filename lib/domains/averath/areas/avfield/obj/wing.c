#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
  SetKeyName("moth wing");
  SetShort("moth wing");
  SetId( ({ "wing" }) );
  SetAdjectives( ({ "moth" }) );
  SetLong(
    "This moth wing is wretched and partly decayed. It has "
    "several veins running through it. However the edge is "
    "very smooth and soft to the touch."
  );
  SetMass(1);
  SetValue(10);
  SetVendorType(VT_TREASURE);
  SetDamagePoints(5);
}
