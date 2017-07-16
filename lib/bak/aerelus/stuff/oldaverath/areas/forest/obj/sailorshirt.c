// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("shirt");
   SetShort("a silk shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "silk" }) );
   SetLong("Luxurious to the touch, the silk shirt is black in color "
           "with dark buttons running up the front.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(100);
   SetDamagePoints(200);
   SetSize(SIZE_MEDIUM);
}
