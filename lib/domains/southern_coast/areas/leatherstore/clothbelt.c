#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen sash");
  SetId( ({ "sash" }) );
  SetAdjectives( ({ "old", "linen" }) );
  SetShort("an old linen sash");
  SetLong(
    "This old sash is made from a light weight linen which offers very little "
    "warmth and protection. The sash could very well be a hand-me-down from a "
    "distant relative with how it is covered in various stains."
  );
  SetMass(20);
  SetValue(500);
  SetWarmth(1);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);   
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BELT);
  SetRepairDifficulty(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1000);
}
