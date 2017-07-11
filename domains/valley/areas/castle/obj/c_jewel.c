#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("degraded jewel");
   SetShort("a degraded jewel");
   SetId( ({ "jewel","gem" }) );
   SetAdjectives( ({ "degraded" }) );
   SetLong("The gem has various types of slime and degradation upon "
           "it, but a talented jeweler could possibly peel some "
           "off.  It's dusty and very ugly, and a strand from some "
           "cobweb hangs off of it.");
   SetMass(3);
   SetValue(5);
   SetVendorType(VT_GEM);
   SetDamagePoints(20);
    SetMaterial( ({ "natural" }) );
   SetDestroyOnSell(1);
   SetProperty("history","The jewel was held by Darken Scarzam, the "
               "phantom of Vale Castle, for so long that it "
               "began to be effected by him and degraded.");
}
