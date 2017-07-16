/* This is a knife coded by Lynna on February 6, 1998
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
		SetKeyName("knife");
		SetShort("a fishing knife");
		SetId( ({ "knife" }) );
		SetAdjectives( ({ "fishing" }) );
		SetLong( "This is a small, little knife.");
		SetWeaponType( "knife" );
		SetClass(9);
		SetMass(20);
		SetDamagePoints(500);
		SetDamageType(PIERCE);
		SetVendorType(VT_WEAPON);
		SetMaterial( ({ "metal" }) );
		SetRepairSkills( ([
			"metal working" : 1,
			"weapon smithing" : 1,
			]) );
		SetRepairDifficulty(5);
		}
