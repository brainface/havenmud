#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("deep grey shirt");
   SetShort("a deep grey shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "deep", "grey" }) );
   SetLong("The deep grey shirt is made of a soft, smooth "
           "textile. It is thin, and doesn't offer much "
           "protection, but allows for decency.");
   SetMass(10);
   SetValue(45);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(350);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(10);
   SetWarmth(10);
   SetProperty("history",
     "This shirt used to be the property of Thrash Greyjoy."
     );
}
