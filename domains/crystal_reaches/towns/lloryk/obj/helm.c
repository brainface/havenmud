#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("helm");
    SetSize(SIZE_SMALL);
    SetId( ({ "helm", "helmet" }) );
    SetAdjectives( ({ "small", "iron" }) );
    SetShort("a small iron helm");
    SetLong("Light reflects off of the conical iron helmet.");
    SetMaterial( ({ "metal" }) );
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetRepairDifficulty(15);
    SetArmourClass(ARMOUR_PLATE);
    SetValue(100);
    SetDamagePoints(650);
    // SetProtection(BLUNT, 4);
    // SetProtection(PIERCE, 2);
    // SetProtection(SLASH, 3);
    SetArmourType(A_HELMET);
    SetWarmth(2);
}
