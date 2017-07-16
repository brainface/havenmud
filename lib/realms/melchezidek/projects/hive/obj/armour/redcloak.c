#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cloak");
  SetShort("a thin red cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "thin", "red" }) );
  SetLong("This is a thin red cloak fashioned from a hemp like material. While"
          " not exquisite craftsmanship, it is not a poorly made garment.");
  SetDamagePoints(350);
  SetValue(200);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(100);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(35);
  SetWarmth(0);
}
