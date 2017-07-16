// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("knife");
   SetShort("a hunting knife");
   SetId(({ "knife" }) );
   SetAdjectives( ({ "hunting" }) );
   SetLong("This knife has a plain white handle with a touch of "
           "silver paint decorating it.  The blade is only sharp "
           "on one side, and is serrated near the handle.");
   SetMass(3);
   SetValue(100);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(300);
   SetWeaponType("knife");
   SetDamageType(SLASH);
//   SetMaterial( ({ "metal" }) );
//   SetRepairDifficulty(5);
//   SetRepairSkills( ([
//                       "metal working" : 0,
//                       "weapon smithing" : 0,
//                  ]) );
   SetClass(10);
}
