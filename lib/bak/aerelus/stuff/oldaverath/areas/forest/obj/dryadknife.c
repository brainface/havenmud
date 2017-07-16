// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_SMELL;

static void create() {
   ::create();
   SetRadiantLight(2);
   SetKeyName("knife");
   SetShort("a luminescent green knife");
   SetId(({ "knife" }) );
   SetAdjectives( ({ "green","luminescent" }) );
   SetLong("Designs in the hilt of the knife depict a simple female "
           "figure screaming.  Stained green, light radiates from "
           "the blade.  Trendils of green smoke rise from the "
           "tip.");
   SetMass(2);
   SetValue(400);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(350);
   SetWeaponType("knife");
   SetDamageType(SLASH|GAS);
//   SetMaterial( ({ "metal" }) );
//   SetRepairDifficulty(10);
//   SetRepairSkills( ([
//                       "metal working" : 1,
//                       "weapon smithing" : 1,
//                  ]) );
   SetClass(15);
   SetSmell("The odors of decay and rot exude from the knife.");
}
