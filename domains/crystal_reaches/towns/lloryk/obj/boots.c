#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int CheckRace();

static void create() {
    armour::create();
    SetKeyName("boots");
    SetAdjectives( ({ "small", "leather", "reinforced", "pair", "of" }) );
    SetId( ({ "boots" }) );
    SetShort("a pair of small leather boots");
    SetLong("The small leather boots have a reinforced toe.");
    SetVendorType(VT_ARMOUR);
    SetProperty("multiples", 1);
    SetMaterials( ({ "leather" }) );
    SetRepairDifficulty(10);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_LEATHER);
    SetMass(30);
    SetValue(80);
    SetDamagePoints(1200);
    // SetProtection(BLUNT , 2);
    // SetProtection(PIERCE, 2);
    // SetProtection(SLASH , 2);
    // SetProtection(COLD  ,2);
    SetArmourType(A_BOOT);
    SetWarmth(2);
}
