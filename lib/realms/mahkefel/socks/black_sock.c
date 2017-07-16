#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("black silk sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "black", "formal" }) );
  SetShort("a formal black sock");
  SetLong(
    "This sleek formal sock is made of jet black silk that stretches to meet "
    "the contours of the wearer's foot. The toe and heel are marked with a "
    "thin golden pinstripe, and the body is embroidered with golden coins in a "
    "way that is probably not intended to look like yellow polka-dots."
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

