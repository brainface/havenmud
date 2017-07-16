#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({"pants"}) );
  SetAdjectives( ({"brown", "pair", "of","cotton"}) );
  SetShort("a pair of cotton pants");
  SetLong(
     "This pair of pants seems to be made of heavy cotton. "
     "The pants are dyed brown to match the limbs of the "
	   "forest trees.");
  SetMass(20);
  SetValue(85);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(250);
  SetWarmth(15);
  // SetProtection(SLASH, 1);
  // SetProtection(PIERCE, 1);
  // SetProtection(COLD, 4);
  SetArmourType(A_PANTS);
  SetSize(SIZE_SMALL);
  SetMaterial( ({"textile"}) );
  SetRepairSkills( ([
     "textile working"  : 2,
     ]) );
  SetRepairDifficulty(5);
  }
