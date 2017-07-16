#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour", "leather armour", "studded armour", "studded leather", 
    "studded leather armour" }) );
    SetAdjectives( ({ "leather" }) );
    SetShort("a studded leather armour");
    SetLong("This is a good, solidly crafted suit of leather armour with metal "
    "studs in it for added protection.");
    SetVendorType(VT_ARMOUR);
    SetMass(190);
    SetWarmth(20);
  SetArmourClass(ARMOUR_REINFORCED);
    SetSize(SIZE_LARGE);
    SetValue(150);
    SetDamagePoints(750);
    // SetProtection(BLUNT, 4);
    // SetProtection(SLASH, 6);
    // SetProtection(PIERCE, 5);
    // SetProtection(HEAT, 2);
    // SetProtection(COLD, 4);
    // SetProtection(SHOCK, 6);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 1);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetArmourType(A_ARMOUR);
}
