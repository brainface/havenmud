#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("armour");
   SetShort("tattered leather armour");
   SetId( ({ "leather armour", "tattered armour", "armour", }) );
   SetLong("This is an old suit of leather armour, that looks to "
           "be sized for a creature of medium build. Tears and filth "
           "cover the armour, and it has quite the aroma.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(100);
   SetValue(15);
   SetDamagePoints(350);
   SetSize(SIZE_SMALL);
}
