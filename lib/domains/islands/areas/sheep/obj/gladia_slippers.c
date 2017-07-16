#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create(); 
	SetArmourClass(ARMOUR_CLOTH); 
	SetMaterials( ({ "textile" }) ); 
	SetKeyName("gold-flecked slippers");
	SetShort("a pair of gold-flecked slippers");
	SetId( ({ "slippers" }) );
	SetAdjectives( ({ "gold", "flecked", "pair", "of" }) );
	SetArmourType(A_BOOT);
  SetDamagePoints(300);
	SetProperty("multiples", 1);
	SetWarmth(10);
	SetValue(200);
	SetSize(SIZE_MEDIUM);
	SetLong(
	  "This well crafted pair of slippers has hints of golden coloring. The slippers appear both "
	  "warm and comfortable."
	);
}
