#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("piercing knife");
   SetShort("a piercing knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "piercing" "pointed","pierce" }) );
   SetLong("The knife tapers down into a single, sharp point of "
           "shining metal.  The sides are hardly developed at all, "
           "making it less of a knife and more of a pierce type "
           "weapon.");
   SetClass(12);
   SetMass(150);
   SetVendorType(VT_WEAPON);
   SetValue(150);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(650);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "metal working" : 2,
                       "weapon smithing" : 2,
                  ]) );
}