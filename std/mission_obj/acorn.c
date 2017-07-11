#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("acorn");
   SetShort("an acorn");
   SetId( ({ "acorn", "nut" }) );
   SetLong("This is a beautiful brown acorn. Some "
           "day this small nut will be a mighty "
           "oak tree.");
   SetMass(10);
   SetValue(0);
   SetDestroyOnSell(1);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(100);
   SetVendorType(VT_TREASURE);
}
