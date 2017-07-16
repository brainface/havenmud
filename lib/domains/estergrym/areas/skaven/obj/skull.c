#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include "../skaven.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("mask");
    SetAdjectives( ({ "strange", "skull"}) );
    SetId( ({ "mask", "skull mask" }) );
    SetShort("a strange skull mask");
    SetLong("This is an unusual mask fashioned from a large "
            "skull, and covered with a hood of black cloth.  "
            "This mask gives the wearer a haunting look.");           
    SetVendorType(VT_ARMOUR);
    SetValue(150);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_NATURAL);
    SetMass(80);
    SetWarmth(5);
    SetMaterials( ({ "natural" }) );
    SetDamagePoints(1000);
    SetRepairDifficulty(20);
    // SetProtection(BLUNT, 2);
    // SetProtection(SLASH, 4);
    // SetProtection(PIERCE, 2);
    // SetProtection(WATER, 1);
    // SetProtection(COLD, 1);
    // SetProtection(HEAT, 1);
    // SetProtection(SHOCK, 1);
    // SetProtection(ACID, 1);
    SetArmourType(A_HELMET);
    SetRestrictLimbs( ({ "head" }) );
    SetWear("This strange helmet sends a chill down your spine.");
}
