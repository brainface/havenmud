// Amelia
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("pelt");
   SetShort("a sleak otter pelt");
   SetId(({ "pelt" }) );
   SetAdjectives( ({ "otter","sleak" }) );
   SetLong("The otter pelt shines with rich health.");
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(1);
   SetValue(100);
   SetDamagePoints(100);
   SetSize(SIZE_MEDIUM);
}
