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
    SetId( ({ "armour", "scale mail armour", "scale", "scale mail",
          "mail", "scale", "shirt", "scale shirt"}) );
    SetAdjectives( ({ "scalemail" }) );
    SetShort("a scale mail shirt");
    SetLong("a good scale mail shirt of steel scales.");
    SetVendorType(VT_ARMOUR);
    SetMass(325);
    SetMaterial("metal");
    SetArmourClass(ARMOUR_PLATE);
    SetSize(SIZE_MEDIUM);
    SetWarmth(0);
    SetValue(380);
    SetDamagePoints(750);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
  }
