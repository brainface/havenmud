
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("crate");
   SetShort("a large crate");
   SetId( ({ "crate", "large crate" }) );
   SetLong("This crate has been filled with something and "
           "sealed along the edges with numerous nails. It "
           "has a single green leaf painted on the top.");
   SetMass(25);
   SetValue(0);
   SetDestroyOnSell(1);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(50);
   SetVendorType(VT_TREASURE);
}
