#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour", "leather" }) );
    SetAdjectives( ({ "leather", "good", }) );
    SetShort("a good leather armour");
    SetLong("This is a good, solidly crafted shirt of leather armour");
    SetVendorType(VT_ARMOUR);
    SetMass(175);
    SetArmourClass(ARMOUR_LEATHER);
    SetSize(SIZE_MEDIUM);
    SetValue(120);
    SetDamagePoints(450);
    SetMaterial( ({ "leather" }) );
    SetWarmth(30);
    SetRepairSkills( ([ "leather working" : 3 ]) );
    SetRepairDifficulty(10);
    // SetProtection(BLUNT, 12);
    // SetProtection(SLASH, 18);
    // SetProtection(PIERCE, 15);
    // SetProtection(HEAT, 2);
    // SetProtection(COLD, 3);
    // SetProtection(SHOCK, 7);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 1);
    SetArmourType(A_BODY_ARMOUR);
}
