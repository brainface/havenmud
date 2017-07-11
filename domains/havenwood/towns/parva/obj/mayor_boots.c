#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of grey leather boots");
   SetId( ({ "boot", "boots" }) );
   SetAdjectives( ({ "grey", "leather" }) );
   SetLong("The grey boots were made of dyed leather. "
           "The making is of high quality and the inside is "
           "a soft red fur.");
   SetMass(20);
   SetValue(95);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetDamagePoints(1200);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(10);
   SetWarmth(6);
   SetProperty("history",
     "These boots used to be the property of Thrash Greyjoy."
     );
   SetProperty("multiples", 1);
}
