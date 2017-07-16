// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetDestroyOnSell(1);
   SetKeyName("oil");
   SetId( ({ "oil" }) );
   SetShort("an oil droplet");
   SetLong("This is a small drop of fish oil, but enough to "
           "possibly be slightly useful.");
   SetMass(1);
   SetValue(1);
   SetVendorType(VT_TREASURE);
   SetMaterial("natural");
   SetDamagePoints(5);
   SetProperty("history","Many fish can have small amounts of "
               "oil collected from them upon their death; this "
               "came from one such fish.");
}
