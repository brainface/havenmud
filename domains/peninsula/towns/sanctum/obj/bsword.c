#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	::create();
	SetShort("a bronze shortsword");
	SetId( ({ "sword", "shortsword" }) );
	SetAdjectives( ({ "short", "bronze" }) );
	SetKeyName("bronze shortsword");
	SetValue(100);
	SetMaterial("metal");
	SetRepairDifficulty(20);
	SetMass(100);
	SetClass(12);
	SetDamagePoints(1200);
	SetWeaponType("slash");
	SetDamageType(SLASH);
	SetLong("This sword of bronze is approximately two and half feet long, "
	        "with a firm hilt. It was designed for use by the average "
	        "soldier, and is more functional than fancy.");
}	        