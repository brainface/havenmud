#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
	SetMaterials( ({ "textile" }) ); 

	SetKeyName("threadbare socks");
	SetShort("a threadbare pair of socks");
	SetId( ({ "socks" }) );
	SetAdjectives( ({ "threadbare", "pair", "of" }) );
	SetArmourType(A_BOOT);
        SetDamagePoints(1000);
	SetProperty("multiples", 1);
	SetWarmth(10);
	SetValue(0);
	SetSize(SIZE_LARGE);
	SetLong("This dull pair of socks seems to be almost worthless. "
	        "However, they look slightly warmer than being barefoot, "
	        "so wearing them is better than nothing.");
}
