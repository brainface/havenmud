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
  SetShort("a thin brown cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "thin", "brown" }) );
  SetLong("This is a thin brown cloak fashioned from a hemp like material. While"
          " not exquisite craftsmanship, it is not a poorly made garment. It is the"
          " cloak worn by the workers of the thri-kreen hive.");
  SetDamagePoints(250);
  SetValue(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(100);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(20);
  SetWarmth(0);
}
