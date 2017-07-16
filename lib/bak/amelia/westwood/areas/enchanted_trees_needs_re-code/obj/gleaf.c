// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>

static void create() {
   item::create();
   SetKeyName("leaf");
   SetShort("a gold leaf");
   SetId( ({ "gold leaf","leaf" }) );
   SetAdjectives( ({ "gold" }) );
   SetLong("The leaf gilted in gold twinkles gloomily in the light.");
   SetMass(7);
   SetValue(20);
   SetVendorType(VT_TREASURE);
   SetMaterial("natural");
}
