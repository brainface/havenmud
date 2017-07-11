#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("glove");
  SetId( ({ "glove" }) );
  SetShort("a studded leather glove");
  SetAdjectives( ({ "studded", "leather"}) );
  SetLong(
    "This glove is made of supple leather, dyed black. A steel plate is riveted to "
    "the back of the hand to provide some extra protection, and a thin layer of "
    "canvas provides padding."
  );
  SetMass(175);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(1000);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);
  SetWear("The studded leather glove feels deceptively heavy.");
}

