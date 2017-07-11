#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("grey cloth pants");
   SetShort("a pair of grey cloth pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "grey", "leather" }) );
   SetLong("The pants are made of a simple, thin "
           "cloth that can't offer that much protection.  "
           "The deep grey color makes the surrounding "
           "area look a little more lively by comparsion.");
   SetMass(10);
   SetValue(45);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_PANTS);
   SetDamagePoints(800);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(10);
   SetWarmth(15);
   SetProperty("history",
     "These pants used to be the property of Thrash Greyjoy."
     );
}
