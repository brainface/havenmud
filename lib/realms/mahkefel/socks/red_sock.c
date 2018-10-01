#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("red silk sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "red", "silk" }) );
  SetShort("a red silk sock");
  SetLong(
    "The entirety of this sock is a vibrant red silk, though close inspection "
    "reveals a faint network of roses and skulls carefully stiched into the "
    "pattern of the fabric."
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

