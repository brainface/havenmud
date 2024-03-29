#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../prisoncamp.h"
inherit LIB_ITEM;

static void create()
{
item::create();
	SetKeyName("spoon");
	SetId( ({ "spoon" }) );
	SetShort("a sharpened spoon");
	SetAdjectives(  ({ "sharpened" })  );
	SetLong("This spoon appears to have been worked against stone to "
		"a razor sharp edge.");
	SetMass(8);
	SetValue(5);
	SetDamagePoints(200);
	SetWeaponType("knife");
	SetDamageType(SLASH);
	SetClass(3);
	SetVendorType(VT_WEAPON);
	SetMaterial(  ({ "metal" })  );
	SetRepairSkills(  ([ 
		"weapon smithing" : 1 
		])  );
	SetRepairDifficulty(2);
}
