#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("chainmail");
    SetSize(SIZE_SMALL);
    SetId( ({ "chain", "chainmail", "mail", "vest" }) );
    SetAdjectives( ({ "chain", "small" }) );
    SetShort("a small vest of chainmail");
    SetLong("Light gleams dully off of the heavy gauge chainmail.");
    SetVendorType(VT_ARMOUR);
    SetMass(750);
    SetArmourClass(ARMOUR_CHAIN);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(15);
    SetValue(300);
    SetDamagePoints(1600);
    // SetProtection(BLUNT, 10);
    // SetProtection(PIERCE, 10);
    // SetProtection(SLASH, 15);
    SetArmourType(A_VEST);
}

