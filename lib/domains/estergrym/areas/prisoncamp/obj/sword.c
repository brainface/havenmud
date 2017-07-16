#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../prisoncamp.h"
inherit LIB_ITEM;

static void create()
{
item::create();
	SetKeyName("sword");
	SetShort("a short sword");
	SetLong("This sword has seen the insides of more than a few "
		"elves. It appears to be intended for short engangements "
		"as prolonged use will cause it to dull quickly.");
	SetId( ({ "sword", "shortsword" }) );
	SetAdjectives(  ({ "short" })  );
	SetMass(120);
	SetValue(170);
	SetDamagePoints(900);
	SetWeaponType("slash");
	SetDamageType(SLASH);
	SetClass(12);
	SetVendorType(VT_WEAPON);
	SetMaterial(  ({ "metal" })  );
	SetRepairSkills(  ([ 
		"weapon smithing" : 2 
		])  );
	SetRepairDifficulty(16);
}
