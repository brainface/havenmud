/* This is an acorn coded by Lynna on February 15, 1998
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
		SetKeyName( "acorn" );
		SetId( ({ "acorn" }) );
		SetAdjectives( ({ "small", "brown" }) );
		SetShort( "a small, brown acorn" );
		SetLong( "This small acorn falls from the trees and is a "
			"favorite food of all the squirrels and chipmunks of "
			"the forest." );
		SetMass(1);
		SetValue(1);
		SetVendorType(VT_TREASURE);
		}
