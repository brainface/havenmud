#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "old", "linen" }) );
  SetShort("an old linen sock");
  SetLong(
    "This old sock is made from a light weight linen which offers very little "
    "warmth and protection. The sock could very well be a hand-me-down from a "
    "distant relative with how it is covered in various stains and small holes "
    "where several of the toes would be."
  );
  SetMass(20);
  SetValue(500);
  SetWarmth(1);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);   
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SOCK);
  SetRepairDifficulty(70);
  SetSize(SIZE_LARGE);
  SetDamagePoints(1000);
}
