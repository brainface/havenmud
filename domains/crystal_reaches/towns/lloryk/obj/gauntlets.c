#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("gauntlet");
    SetSize(SIZE_SMALL);
    SetId( ({ "gauntlet", "glove", }) );
    SetShort("a fine chainmail gauntlet");
    SetLong("The weave is almost delicate in the small chainmail gauntlet.");
    SetVendorType(VT_ARMOUR);
    SetMass(25);
    SetValue(100);
    SetArmourClass(ARMOUR_CHAIN);
    SetDamagePoints(750);
    // SetProtection(BLUNT, 5);
    // SetProtection(PIERCE, 5);
    // SetProtection(SLASH, 10);
    SetArmourType(A_GLOVE);
    SetMaterial("metal");
    SetRepairDifficulty(10);
    SetWarmth(2);
}
