#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create () {

    armour::create();

    SetKeyName("metal shield");
    SetId( ({ "shield", "metal shield"}) );
    SetAdjectives( ({ "metal" }) );
    SetShort("a large metal shield");
    SetLong(
     "This large metal shield looks to be sturdy and strong. It "
     "has a large emblem engraved upon it that forms the shape of "
     "an orc with a horn. "
    );
    SetSize(SIZE_LARGE);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "armour smithing" : 7,
          "metal working" : 7,
					]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_PLATE);
    SetValue(350);
    SetMass(500);
    SetDamagePoints(1115);
    // SetProtection(BLUNT, 7);
    // SetProtection(SLASH, 7);
    // SetProtection(PIERCE, 5);
    // SetProtection(WATER, 1);
    // SetProtection(PIERCE, 5);
    SetArmourType(A_SHIELD);
}
