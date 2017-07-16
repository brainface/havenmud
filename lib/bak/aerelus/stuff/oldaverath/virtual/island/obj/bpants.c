#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("pants");
   SetShort("a black pair of pants");
   SetId( ({ "pants", "pair of pants", }) );
   SetAdjectives( ({ "black" }) );
   SetLong("This is a fancy black pair of pants, which appears to "
           "have been rather well taken care of, save for the "
           "occasional tear and a bit of filth at the bottom. ");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(65);
   SetValue(20);
   SetDamagePoints(250);
   SetSize(SIZE_MEDIUM);
}
