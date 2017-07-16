/* This is a fishing pole for my fisherman coded by Lynna on February 11, 1998
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
	pole::create();
		SetKeyName("fishing pole");
		SetShort("a long, wooden, fishing pole");
		SetId( ({ "pole", "fishing pole" }) );	
		SetAdjectives( ({ "long", "wooden", "fishing" }) );
		SetLong( "This is a long, wooden fishing pole, that is used "
			"by the fishermen of the sea.");
		SetClass(1);
		SetMass(30);
		SetDamagePoints(300);
		SetChance(20);
		SetStrength(200);
		SetValue(10);
		SetVendorType( VT_TREASURE | VT_FISHING );
		SetMaterial( ({ "wood" }) );
		SetRepairSkills( ([
			"wood working" : 1,
			"weapon smithing" : 1,
		]) );
		SetRepairDifficulty(5);
}

