#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../prisoncamp.h"
inherit LIB_ITEM;

static void create()
{
item::create();
	SetKeyName("rod");
	SetId( ({ "rod" }) );
	SetAdjectives(  ({ "long", "thin" })  );
	SetShort("a long thin rod");
	SetLong("A three foot thin metal rod used to discipline elves.");
	SetMass(80);
	SetValue(150);
	SetDamagePoints(1100);
	SetWeaponType("pole");
	SetDamageType(BLUNT);
	SetClass(12);
	SetVendorType(VT_WEAPON);
	SetMaterial(  ({ "metal" })  );
	SetRepairSkills(  ([ "weapon smithing" : 1 ])  );
	SetRepairDifficulty(8);
}