// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
#include <damage_types.h>

static void create() {
   item::create();
   SetKeyName("branch");
   SetShort("a thick branch");
   SetId( ({ "thick branch","branch" }) );
   SetAdjectives( ({ "thick" }) );
   SetLong("Some silver and gold gilted leaves hang to the edges of the "
           "branch, which is shaped like a sturdy club.");
   SetMass(40);
   SetValue(40);
   SetVendorType(VT_WEAPON);
   SetClass(7);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(800);
   SetDestroyOnSell(1);
   SetMaterial( ({ "wood" }) );
   SetRepairSkills( ([
		"wood working" : 1,
		"weapon smithing" : 1,
		]) );
   SetRepairDifficulty(5);
}