#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("shirt");
   SetShort("a tattered shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "tattered" }) );
   SetLong("Large rips and tears cover this shirt, making it "
           "nearly pointless to wear because it really doesn't keep "
           "that much heat in. And it certainly doesn't provide any "
           "noticeble combat protection.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(35);
   SetValue(5);
   SetDamagePoints(150);
   SetSize(SIZE_MEDIUM);
}
