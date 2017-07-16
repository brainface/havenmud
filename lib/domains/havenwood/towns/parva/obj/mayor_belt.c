#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a deep grey belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "deep", "grey" }) );
   SetLong("The belt is a deep grey color. It isn't very long, but "
           "was carefully crafted.  Stitched in white are some "
           "simple designs of dragons and krakens fighting.");
   SetMass(2);
   SetValue(35);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BELT);
   SetDamagePoints(1200);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(10);
   SetWarmth(3);
   SetProperty("history",
     "This belt used to be the property of Thrash Greyjoy."
     );
}
