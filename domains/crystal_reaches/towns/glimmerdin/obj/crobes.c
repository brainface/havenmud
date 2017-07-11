#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pristine robe");
  SetId( ({ "robe", }) );
  SetAdjectives( ({ "pristine", "off", "white", }) );
  SetShort("a pristine off-white robe");
  SetLong(
    "This robe is a perfect, off-white cloth material that is "
    "well designed and very functional."
    );
  SetVendorType(VT_CLOTHING);
  SetMass(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(5);
  SetWarmth(18);
  SetSize(SIZE_SMALL);
  SetValue(15);
  SetDamagePoints(2000);
  // SetProtection(HEAT, 10);
  // SetProtection(COLD, 10);
  SetArmourType(A_CLOAK);
}
