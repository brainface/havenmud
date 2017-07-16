#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
armour::create();
  SetKeyName("black robe");
  SetId( ({ "robe" }) );
  SetShort("an old black robe");
  SetAdjectives( ({ "black", "old" }) );
  SetLong(
    "This old black robe is made from a light weight linen which offers very little "
    "warmth and protection. The robe could very well be a hand-me-down from a "
    "distant relative with how it is covered in various stains."
  );
  SetWarmth(2);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(70);
  SetSize(SIZE_LARGE);
  SetMass(80);
  SetValue(300);
  SetDamagePoints(1400);
}
