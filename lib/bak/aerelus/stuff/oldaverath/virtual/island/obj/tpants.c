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
   SetShort("a tattered pair of pants");
   SetId( ({ "pants", "pair of pants", }) );
   SetAdjectives( ({ "tattered" }) );
   SetLong("Large rips and tears cover these pants, making them "
           "nearly pointless to wear because they really don't keep "
           "that much heat in. And they certainly don't provide any "
           "noticeble combat protection.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(45);
   SetValue(5);
   SetDamagePoints(150);
   SetSize(SIZE_MEDIUM);
}
