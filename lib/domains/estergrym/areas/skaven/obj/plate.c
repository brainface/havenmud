#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include "../skaven.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("breastplate");
    SetId( ({ "breastplate", "plate" }) );
    SetShort("a breastplate");
    SetLong("This is a somewhat small chest protector made "
            "from a single piece of metal.  It has been painted "
            "red and is secured with thick leather straps.");
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([
          "metal working" : 8,
          "armour smithing" : 8,
          ]) );
    SetRepairDifficulty(10);                  
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_PLATE);
    SetVendorType(VT_ARMOUR);
    SetValue(750);
    SetMass(300);
    SetDamagePoints(1500);
    // SetProtection(BLUNT, 8);
    // SetProtection(SLASH, 12);
    // SetProtection(PIERCE, 8);
    // SetProtection(WATER, 3);
    // SetProtection(COLD, 3);
    // SetProtection(HEAT, 3);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 1);
    SetArmourType(A_VEST);
    SetWear("The breastplate is surprisingly well balanced.");
}
