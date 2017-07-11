/* This is a shovel coded by Lynna on February 11, 1998
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
	item::create();
		SetKeyName( "shovel" );
		SetId( ({ "shovel" }) );
		SetShort( "a short shovel" );
		SetAdjectives( ({ "short" }) );
		SetLong( "This short shovel is used especially by children "
			"for digging in the sand." );
		SetMass(20);
    SetDamagePoints(2000);
		SetValue(25);
		SetVendorType(VT_WEAPON);
		}
