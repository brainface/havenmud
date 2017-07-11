#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

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
    SetArmourClass(ARMOUR_CHAIN);
    SetSize(SIZE_SMALL);
    SetValue(380);
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([ "armour smithing" : 7 ]) );
    SetRepairDifficulty(15);
    SetDamagePoints(750);
    // SetProtection(BLUNT, 10);
    // SetProtection(SLASH, 16);
    // SetProtection(PIERCE, 14);
    // SetProtection(HEAT, 1);
    // SetProtection(COLD, 1);
    // SetProtection(SHOCK, 0);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 2);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
  }
