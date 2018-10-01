#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen glove");
  SetId( ({ "glove" }) );
  SetAdjectives( ({ "old", "linen" }) );
  SetShort("an old linen glove");
  SetLong(
    "This old glove is made from a light weight linen which offers very little "
    "warmth and protection. The glove could very well be a hand-me-down from a "
    "distant relative with how it is covered in various brown and black stains. "
  );
  SetMass(20);
  SetValue(500);
  SetWarmth(1);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);   
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_GLOVE);
  SetRepairDifficulty(70);
  SetDamagePoints(800);
}

int GetSize() {
  object e;
  if (living(e = environment()))
     return e->GetSize();
     return SIZE_MEDIUM;
}
