#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("elaborate knife");
   SetShort("an elaborately detailed knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "elaborately", "detailed", "elaborate" }) );
   SetLong("There is something exceptional about this knife. "
           "Its quality is above average, and its has a detailed "
           "design of a kraken in the hilt.");
   SetMass(10);
   SetValue(350);
   SetClass(14);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(1500);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetProperty("history",
     "This knife used to be the property of Thrash Greyjoy."
     );
}
