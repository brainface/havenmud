//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
armour::create(); 
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("tunic");
  SetId( ({ "tunic" }) );
  SetShort("a short tunic");
  SetAdjectives( ({ "short" }) );
  SetLong("The flax tunic is a well-made piece of clothing that covers "
          "most of the body without constraining the limbs. It is made "
          "of simple, unrefined fibers and is an almost-white color."
  );
  SetWarmth(20);
  SetProperty("multiples", 1);
  SetMaterial("texile");
  SetRepairDifficulty(15);
  SetMass(80);
  SetSize(SIZE_MEDIUM);
  SetValue(75);
  SetDamagePoints(400);
}
