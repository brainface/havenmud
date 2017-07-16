/* These are feathers found on the beach coded by Lynna on February 11, 1998
*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
		SetKeyName("feather");
		SetShort("a long, white feather");
		SetId( ({ "feather" }) );
		SetAdjectives( ({ "long", "white" }) );
		SetLong( "This long, white feather is found on the sands of "
			"the beach where many of the birds are found." );
		SetClass(1);
		SetMass(5);
		SetValue(2);
		SetVendorType(VT_TREASURE);
		}
