#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
  SetId( ({ "armour", "mail", "shirt" }) );
    SetAdjectives( ({ "scale", "mail", "scalemail" }) );
    SetShort("a scale mail shirt");
    SetLong(
      "A good scale mail shirt of steel scales. "
      "It appears to be of a size suitable for "
      "the smaller races."
    );
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_PLATE);
    SetMass(325);
    SetMaterial("metal");
    SetSize(SIZE_SMALL);
    SetWarmth(0);
    SetValue(380);
    SetDamagePoints(750);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
  }
