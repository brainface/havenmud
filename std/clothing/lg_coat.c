#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
    SetSize(SIZE_LARGE);
	SetMaterials( ({ "textile" }) ); 

	SetKeyName("bearskin coat");
	SetId( ({ "coat" }) );
	SetAdjectives( ({ "bearskin" }) );
	SetArmourType(A_ARMOUR);
        SetDamagePoints(1000);
	SetValue(0);
	SetWarmth(40);
	SetShort("a bearskin coat");
	SetLong("This is a bear skin coat, which looks very warm.");
}
