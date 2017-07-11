#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
	SetMaterials( ({ "textile" }) ); 

	SetKeyName("threadbare shoes");
	SetShort("a threadbare pair of shoes");
	SetId( ({ "shoes" }) );
	SetAdjectives( ({ "threadbare", "pair", "of" }) );
	SetArmourType(A_BOOT);
        SetDamagePoints(1000);
	SetProperty("multiples", 1);
	SetWarmth(10);
	SetValue(0);
	SetSize(SIZE_VERY_SMALL);
	SetLong("This dull pair of shoes seems to be almost worthless. "
	        "However, they look slightly warmer than being barefoot, "
	        "so wearing them is better than nothing.");
}
