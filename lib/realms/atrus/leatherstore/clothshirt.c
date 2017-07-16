#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "old", "linen" }) );
  SetShort("an old linen shirt");
  SetLong(
    "This old shirt is made from a light weight linen which offers very little "
    "warmth and protection. The shirt could very well be a hand-me-down from a "
    "distant relative with how it is covered in various stains. "   
  );
  SetMass(50);
  SetMaterial( ({ "textile" }) );
  SetValue(2000);  
  SetArmourClass(ARMOUR_CLOTH);  
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  SetRepairDifficulty(70);
  SetWarmth(2);
  SetDamagePoints(1000);
}

int GetSize() {
  object e;
  if (living(e = environment()))
     return e->GetSize();
     return SIZE_MEDIUM;
}
