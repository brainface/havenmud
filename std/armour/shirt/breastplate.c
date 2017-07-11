#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("breastplate");
    SetId( ({  "breastplate", "armour","plate" }) );
    SetShort("a bronze breastplate");
    SetLong("a plain bronze breastplate");
    SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_PLATE);
    SetMass(375);
    SetMaterial("metal");
    SetWarmth(0);
    SetValue(325);
    SetSize(SIZE_MEDIUM);
    SetDamagePoints(1000);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
  }
