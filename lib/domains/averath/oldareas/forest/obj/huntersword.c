// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("sword");
   SetShort("a simple longsword");
   SetId(({ "longsword","sword" }) );
   SetAdjectives( ({ "simple" }) );
   SetLong("This simple longsword is made from strong iron, and has little "
           "decoration at the hilt beyond a simple swirl.");
   SetMass(30);
   SetValue(80);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(300);
   SetWeaponType("slash");
   SetDamageType(SLASH);
//   SetMaterial( ({ "metal" }) );
//   SetRepairDifficulty(5);
//   SetRepairSkills( ([
//                       "metal working" : 0,
//                       "weapon smithing" : 0,
//                  ]) );
   SetClass(18);
}
