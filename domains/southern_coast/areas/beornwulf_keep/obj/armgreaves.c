#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("arm greaves");
    SetId( ({ "greaves", "arm greaves" }) );
    SetShort("metal arm greaves");
    SetLong("This set of metal arm greaves can be worn together with the rest "
            "of the full plate mail, or by themselves.  Because of a strap in "
            "the back that holds them on, they must both be worn together.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 10,
          "armour smithing" : 8,
					]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
  	SetArmourClass(ARMOUR_PLATE);
    SetValue(600);
    SetMass(350);
    SetDamagePoints(2000);
    // SetProtection(BLUNT, 26);
    // SetProtection(SLASH, 26);
    // SetProtection(PIERCE, 12);
    // SetProtection(WATER, 5);
    // SetProtection(COLD, 5);
    // SetProtection(HEAT, 5);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 4);
    SetArmourType(A_ARMOUR);
    SetRestrictLimbs( ({ "left arm", "right arm" }) );
    SetWear("You push your arms through the straps on the greaves.");
}
