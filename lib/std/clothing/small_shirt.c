#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
	SetMaterials( ({ "textile" }) ); 

	SetKeyName("threadbare shirt");
	SetShort("a threadbare shirt");
	SetId( ({ "shirt" }) );
	SetAdjectives( ({ "threadbare",  }) );
	SetArmourType(A_SHIRT);
        SetDamagePoints(1000);
	SetWarmth(15);
	SetValue(0);
	SetSize(SIZE_SMALL);
	SetLong("This dull shirt seems to be almost worthless. "
	        "However, it look slightly warmer than being naked, "
	        "so wearing it is better than nothing.");
}
