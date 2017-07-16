#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
	SetMaterials( ({ "textile" }) ); 

	SetKeyName("threadbare pants");
	SetShort("a threadbare pair of pants");
	SetId( ({ "pants" }) );
	SetAdjectives( ({ "threadbare", "pair", "of" }) );
	SetArmourType(A_PANTS);
        SetDamagePoints(1000);
	SetWarmth(20);
	SetValue(0);
	SetSize(SIZE_VERY_SMALL);
	SetLong("This dull set of pants seems to be almost worthless. "
	        "However, they look slightly warmer than being naked, "
	        "so wearing them is better than nothing.");
}
	      
