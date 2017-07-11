#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../prisoncamp.h"
inherit LIB_ITEM;

static void create()
{
	item::create();
	SetKeyName("sledge");
	SetId(  ({ "sledge", "hammer" })  );
	SetShort("a sledge hammer");
	SetLong( "This sledge hammer was used by an elven "
		"prisoner until someone killed him in cold blood.  ");
	SetMass(200);
	SetValue(150);
	SetDamagePoints(1000);
	SetWeaponType("blunt");
	SetDamageType(BLUNT);
	SetClass(13);
	SetVendorType(VT_WEAPON);
	SetRepairSkills(  ([ 
		"weapon smithing" : 4 
		])  );
	SetMaterial("natural");
	SetRepairDifficulty(10);
}