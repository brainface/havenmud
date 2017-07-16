#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("cloth robe");
    SetSize(SIZE_SMALL);
    SetId( ({ "robe", "robes", }) );
    SetAdjectives( ({ "cloth", "stained", "off", "white" }) );
    SetShort("a stained off-white cloth robe");
    SetLong("Ink stains the cuffs and sleeves of this neutral colored robe.");
    SetVendorType(VT_CLOTHING);
    SetWarmth(30);
    SetMass(15);
    SetArmourClass(ARMOUR_CLOTH);
    SetValue(15);
    SetMaterial("textile");
    SetRepairDifficulty(5);
    SetDamagePoints(80);
    // SetProtection(HEAT, 2);
    // SetProtection(COLD, 4);
    SetArmourType(A_CLOAK);
}
