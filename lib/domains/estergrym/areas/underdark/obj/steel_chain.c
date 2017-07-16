#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour", "shirt", "chainmail" }) );
    SetAdjectives( ({ "chainmail" }) );
    SetShort("a chainmail shirt");
    SetLong("a good chainmail shirt of steel.");
    SetVendorType(VT_ARMOUR);
    SetMass(375);
    SetValue(325);
    SetDamagePoints(620);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_CHAIN);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(20);
    SetWarmth(0);
    SetRepairSkills( ([ "armour smithing" : 5 ]) );
    SetRepairDifficulty(13);
    // SetProtection(BLUNT, 8);
    // SetProtection(SLASH, 14);
    // SetProtection(PIERCE, 10);
    // SetProtection(HEAT, 0);
    // SetProtection(COLD, 0);
    // SetProtection(SHOCK, 0);
    // SetProtection(WATER, 0);
    // SetProtection(ACID, 1);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
  }
