#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create();
  SetKeyName("leather collar");
  SetSize(SIZE_VERY_SMALL);
  SetShort("a leather dog collar");
  SetDestroyOnSell(1);
  SetId( ({ "collar" }) );
  SetAdjectives( ({ "leather", "dog" }) );
  SetLong("This collar is a leathery mark of submission to the bandit lords.");
  SetValue(50);
  SetMaterials( ({ "leather" }) );
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_REINFORCED);
  SetDamagePoints(1000);
  SetMass(20);
  SetWarmth(5);
  SetVendorType(VT_ARMOUR|VT_CLOTHING);
}
