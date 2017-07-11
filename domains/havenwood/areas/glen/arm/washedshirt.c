#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>

#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetMaterial("textile");
    SetWarmth(10);
    SetRepairSkills( ([
       "textile working" : 3,
       "armour smithing" : 4
       ]) );
    SetRepairDifficulty(20);
    SetKeyName("freshly washed shirt");
    SetId( ({  "freshly washed shirt", "cotton shirt","shirt" }) );
    SetShort("a freshly washed shirt");
    SetLong("The cotton shirt has just been washed.");
    SetVendorType(VT_CLOTHING);
    SetMass(35);
    SetValue(120);
    SetDamagePoints(150);
    SetArmourClass(ARMOUR_CLOTH);
    // SetProtection(BLUNT, 1);
    // SetProtection(SLASH, 3);
    // SetProtection(PIERCE, 2);
    // SetProtection(WATER, 1);
    // SetProtection(SHOCK, 1);
    // SetProtection(COLD, 5);
    // SetProtection(HEAT, 2);
    // SetProtection(ACID, 1);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetWear("The clean shirt feels very comfortable.");
    SetArmourType(A_SHIRT);
    SetSize(SIZE_SMALL);
  }
