#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("partridge feather");
   SetShort("a gray partridge feather");
   SetId( ({ "feather" }) );
   SetAdjectives( ({ "gray" }) );
   SetLong("The feather is gray with black stripes.");
   SetMass(1);
   SetValue(7);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(77);
   SetMaterial( ({ "natural" }) );
}
