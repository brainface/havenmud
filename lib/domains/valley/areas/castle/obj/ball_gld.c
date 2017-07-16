#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("golden ball");
   SetShort("a golden ball");
   SetId( ({ "ball","sphere" }) );
   SetAdjectives( ({ "golden","gold","small" }) );
   SetLong("The small golden sphere is slightly flawed, but is "
           "still absolutely beautiful in appearance.");
   SetMass(5);
   SetValue(50);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(65+random(20));
   SetMaterial( ({ "metal" }) );
}
