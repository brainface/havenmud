// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
#include <damage_types.h>
 
static void create() {
   item::create();
   SetKeyName("branch");
   SetShort("a long branch");
   SetId( ({ "long branch","branch" }) );
   SetAdjectives( ({ "long" }) );
   SetLong("Some silver gilted leaves hang to the edges of the long, "
		"pole-like branch.");
   SetMass(35);
   SetValue(30);
   SetVendorType(VT_WEAPON);
   SetClass(6);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(500);
   SetDestroyOnSell(1);
   SetMaterial( ({ "wood" }) );
   SetRepairSkills( ([
		"wood working" : 1,
		"weapon smithing" : 1,
		]) );
   SetRepairDifficulty(5);
}