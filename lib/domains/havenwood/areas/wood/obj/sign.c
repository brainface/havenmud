/* This is a sign for the beach, coded by Lynna on February 11, 1998
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
		SetKeyName( "sign" );
		SetId( ({ "sign"}) );
		SetShort( "a rectangular, wooden sign" );
		SetAdjectives( ({ "rectangular", "wooden" }) );
		SetRead( "default", "The sign warns against swimming." );
		SetPreventGet( "The sign is firmly rooted." );
		SetLong( "This wooden sign warns against the dangers of "
			"swimming in these rough waters.");
		SetMass(20);
		}
