#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("soft robes");
  SetShort("softly flowing silk robes");
  SetId( ({ "robe", "robes", }) );
  SetAdjectives( ({ "flowing", "softly", "soft", "silk" }) );
  SetLong("These are long and flowing silk robes.");
  SetValue(800);
  SetMass(50);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetVendorType(VT_TREASURE|VT_CLOTHING);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(150);
  }
