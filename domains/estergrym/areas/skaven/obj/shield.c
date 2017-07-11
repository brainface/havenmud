#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include "../skaven.h"

inherit LIB_ARMOUR;

static void create () {

    armour::create();

    SetKeyName("metal shield");
    SetId( ({ "shield", "metal shield"}) );
    SetAdjectives( ({ "metal" }) );
    SetShort("a large-sized metal shield");
    SetLong("This large sized metal shield is oblong in shape and has been " 
       			"painted red and bears a large black rune of unknown "
       			"origin that looks similar to a stylized triangle.");
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([
        "armour smithing" : 5,
        "metal working" : 5,
				]) );
    SetRepairDifficulty(10);
    SetArmourClass(ARMOUR_PLATE);
    SetSize(SIZE_MEDIUM);
    SetVendorType(VT_ARMOUR);
    SetValue(350);
    SetDamagePoints(1000);
    // SetProtection(BLUNT, 7);
    // SetProtection(SLASH, 7);
    // SetProtection(PIERCE, 7);
    // SetProtection(WATER, 1);
    // SetProtection(HEAT, 1);
    // SetProtection(COLD, 1);
    // SetProtection(ACID, 1);
    SetArmourType(A_SHIELD|A_WEAPON);
}
