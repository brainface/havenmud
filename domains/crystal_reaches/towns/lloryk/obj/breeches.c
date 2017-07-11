#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("breeches");
    SetSize(SIZE_SMALL);
    SetId( ({ "breeches", "pants" }) );
    SetShort("a pair of small leather breeches");
    SetLong("Signs of wear mark the knees and cuffs of the leather breeches.");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetValue(80);
    SetArmourClass(ARMOUR_LEATHER);
    SetMaterial( ({ "leather" }) );
    SetRepairDifficulty(5);
    SetDamagePoints(400);
    // SetProtection(BLUNT, 1);
    // SetProtection(PIERCE, 3);
    // SetProtection(SLASH, 3);
    // SetProtection(COLD,3);
    SetArmourType(A_PANTS);
    SetWarmth(30);
}
