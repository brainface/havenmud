#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("sword");
   SetShort("an iron sword");
   SetId(({ "sword" }) );
   SetAdjectives( ({ "iron" }) );
   SetLong("The craftman who made this sword aimed for simplicity, "
           "neglecting to decorate the weapon in any way except "
           "for placing a small engraving on the hilt, which reads "
           "Averath.  The blade is made of plain iron. ");
   SetMass(40);
   SetValue(100);
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
   SetClass(15);
}
