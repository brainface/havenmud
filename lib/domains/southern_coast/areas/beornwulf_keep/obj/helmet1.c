#include <armour_types.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>

inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetKeyName("horned helmet");
    SetId( ({ "helmet", "horned helmet" }) );
    SetAdjectives( ({ "horned" }) );
    SetShort("a horned helmet");
  	SetWarmth(2);
    SetLong("This large metal helmet covers the entire head, with a slit "
            "towards the top to see through, and two enormous horns protruding "
            "from the top.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 8,
          "armour smithing" : 9,
					]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
  	SetArmourClass(ARMOUR_PLATE);
    SetDamagePoints(2000);
    SetMass(180);

    // SetProtection(BLUNT, 18);
    // SetProtection(SLASH, 19);
    // SetProtection(PIERCE, 12);
		// SetProtection(WATER, 10);
    // SetProtection(COLD, 10);
    // SetProtection(HEAT, 6);
    // SetProtection(ACID, 7);
    SetArmourType(A_HELMET);
    SetWear("You slide the helmet over your head.");
    SetRestrictLimbs( ({ "head" }) );
    SetValue(1000);
}
