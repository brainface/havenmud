#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("shield");
    SetSize(SIZE_SMALL);
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "small", "wooden", "iron", "reinforced" }) );
    SetShort("a small iron-reinforced wooden shield");
    SetLong("The small round wooden shield is bound by iron around the "
            "edges");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetValue(70);
    SetArmourClass(ARMOUR_NATURAL);
    SetMaterial("wood");
    SetRepairDifficulty(10);
    SetDamagePoints(400);
    // SetProtection(BLUNT, 2);
    // SetProtection(PIERCE, 4);
    // SetProtection(SLASH, 2);
    SetArmourType(A_SHIELD);
}

