#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include "../prisoncamp.h"
inherit LIB_ARMOUR;

static void create()

{
	armour::create();
	SetKeyName("cloak");
	SetShort("a black cloak");
	SetId(  ({ "cloak" })  );
	SetAdjectives(  ({ "black" })  );
	SetLong("This long black cloak seems perfect for anyone practicing "
		"the black arts.  ");
	SetMass(70);
	SetValue(110);
  SetMaterial("textile");
  SetWarmth(20);
  SetProperty("multiples", 1);
	SetDamagePoints(900);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
	// SetProtection(COLD, 8);
	// SetProtection(HEAT, 3);
	// SetProtection(WATER, 3);
	// SetProtection(ACID, 2);
	// SetProtection(SHOCK, 4);
	// SetProtection(BLUNT, 2);
	// SetProtection(SLASH, 5);
	// SetProtection(PIERCE,2);
	SetArmourType(A_CLOAK);
	SetVendorType(VT_CLOTHING);
}
