#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("leather shield");
    SetId("shield");
    SetAdjectives("leather");
    SetShort("a leather shield");
    SetLong("This shield is made of boiled leather stretched over "
            "a wood frame. It's about 2 feet across and is fairly "
            "light.");
    SetMass(160);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_LEATHER);
    SetValue(100);
    SetDamagePoints(500);
    // SetProtection(SLASH, 6);
    // SetProtection(BLUNT, 5);
    // SetProtection(PIERCE, 1);
    SetMaterial("leather");
    SetWarmth(0);
    SetRepairSkills( ([
                       "leather working" : 3,
                       "armour smithing" : 1,
                   ]) );
    SetRepairDifficulty(20);
    SetArmourType(A_SHIELD);
    SetVendorType(VT_ARMOUR);
}
