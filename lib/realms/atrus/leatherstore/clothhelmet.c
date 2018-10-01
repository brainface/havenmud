
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "old", "linen" }) );
  SetShort("an old linen mask");
  SetLong(
    "This old mask is made from a light weight linen which offers very little "
    "warmth and protection. The mask could very well be a hand-me-down from a "
    "distant relative with how it is covered in various reddish stains. Two small "
    "holes in the mask allow the wearer to see."     
  );
  SetMass(20);
  SetValue(500);
  SetWarmth(2);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);   
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_VISOR);
  SetRepairDifficulty(70);
  SetDamagePoints(800);
}

int GetSize() {
  object e;
  if (living(e = environment()))
     return e->GetSize();
     return SIZE_MEDIUM;
}
