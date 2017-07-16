#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("breastplate");
    SetId( ({ "breastplate" }) );
    SetShort("a breastplate");
    SetLong("This huge slab of plate metal fits over the front of the torso, "
            "straps holding it on in the back.  It provides excellent "
            "protection against any physical attack.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 9,
          "armour smithing" : 10,
					]) );
	  SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_PLATE);
    SetValue(1750);
    SetMass(750);
    SetDamagePoints(2500);
    // SetProtection(BLUNT, 30);
    // SetProtection(SLASH, 30);
    // SetProtection(PIERCE, 15);
    // SetProtection(WATER, 6);
    // SetProtection(COLD, 6);
    // SetProtection(HEAT, 6);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 5);
    SetArmourType(A_VEST);
    SetRestrictLimbs( ({ "torso" }) );
    SetWear("The breastplate is heavy and appears to surround you "
    			  "with an aura of magical protection.");
}
