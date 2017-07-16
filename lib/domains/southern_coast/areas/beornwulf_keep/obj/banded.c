#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {

    armour::create();
    SetKeyName("banded armour");
    SetId( ({ "armour", "banded armour"}) );
    SetAdjectives( ({ "banded" }) );
    SetShort("banded armour");
    SetLong("This armour is made of overlapping strips of metal sewn to "
            "a backing of leather and chain mail.");
    SetMaterial( ({ "metal", "leather" }) );
    SetWarmth(5);
    SetRepairSkills( ([
          "metal working" : 4,
          "leather working" : 5,
          "armour smithing" : 6,
					]) );
    SetRepairDifficulty(25);
    SetArmourClass(ARMOUR_REINFORCED);
    SetVendorType(VT_ARMOUR);
    SetMass(140);
    SetValue(300);
    SetDamagePoints(900);
    // SetProtection(BLUNT, 7);
    // SetProtection(SLASH, 8);
    // SetProtection(PIERCE, 8);
    SetArmourType(A_ARMOUR);
    SetRestrictLimbs( ({ "right arm", "left arm", "torso"}) );
}
