#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("golden silk sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "golden", "silk" }) );
  SetShort("a golden silk sock");
  SetLong(
    "This long formal sock is made of fine yellow silk, almost golden. Thick "
    "black thread ribs the cuff and heel for structure, and the sole is made "
    "of a softer, downy thread for comfort. Fine black roses embroider the leg "
    "in a carefully interlaced pattern."
  );
  SetMass(20);
  SetValue(1000);
  SetWarmth(1);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SOCK);
  SetRepairDifficulty(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1000);
}

