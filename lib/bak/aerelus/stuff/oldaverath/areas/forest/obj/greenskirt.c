// amelia
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("skirt");
   SetShort("a forest green skirt");
   SetId( ({ "skirt" }) );
   SetAdjectives( ({ "forest","green" }) );
   SetLong("Tough, rough wool was used to make this forest green skirt.  It "
           "has a scratchy touch to it.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(5);
   SetValue(30);
   SetProperty("multiples",1);
   SetDamagePoints(250);
   SetSize(SIZE_MEDIUM);
}
