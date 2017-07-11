#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("ancient bracelet");
   SetShort("an ancient bracelet");
   SetId( ({ "bracelet" }) );
   SetAdjectives( ({ "ancient" }) );
   SetLong("Old, scratched, and dusty gems are linked together to "
           "form this bracelet.");
   SetMass(4);
   SetValue(55);
   SetVendorType(VT_GEM|VT_ARMOUR);
   SetDamagePoints(85);
   // SetProtection(GAS,7);
   // SetProtection(WATER,7);
   SetProperty("magic","Being so close to death for a long time, "
                       "the bracelet has build up defences to gas "
                       "and water.");
   SetMaterial( ({ "metal","natural" }) );
   SetDestroyOnSell(1);
}
