/* This is a rock for the beach coded by Lynna on February 11, 1998
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
		SetKeyName( "rock" );
		SetId( ({ "rock" }) );
		SetShort( "a small, round rock" );
		SetAdjectives( ({ "small" , "round" }) );
		SetLong( " This rock is small and round. It usually lies on "
			 "the sandy shores of the beach." );
		SetMass(10);
		SetValue(5);
		SetDamagePoints(80);
		SetClass(3);
		SetDamageType(BLUNT);
		SetVendorType(VT_TREASURE);
		}
