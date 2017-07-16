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
    SetAdjectives( ({ "cloth", "light", }) );
    SetShort("a light cloth robe");
    SetLong("An incredibly light cloth makes up this burgundy robe.");
    SetVendorType(VT_CLOTHING);
    SetMass(15);
    SetMaterials( ({ "textile" }) );
    SetValue(15);
    SetArmourClass(ARMOUR_CLOTH);
    SetRepairDifficulty(5);
    SetDamagePoints(80);
    // SetProtection(HEAT, 2);
    // SetProtection(COLD, 4);
    SetArmourType(A_CLOAK);
    SetWarmth(15);
}
