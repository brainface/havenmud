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
   SetKeyName("boots");
   SetShort("a pair of leather boots");
   SetId( ({ "boots","pair" }) );
   SetAdjectives( ({ "pair of","leather","brown" }) );
   SetLong("Rough leather forms this pair of brown boots, which can be "
           "secured to a foot with thick brown laces.");
   SetArmourType(A_BOOT);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(2);
   SetValue(200);
   SetDamagePoints(450);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}
