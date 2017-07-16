#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("leg greaves");
    SetId( ({ "greaves", "leg greaves" }) );
    SetShort("metal leg greaves");
    SetLong("This set of metal leg greaves covers both legs from ankle to "
          "thigh with a thick metal plating.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 9,
          "armour smithing" : 9,
					]) );
    SetRepairDifficulty(50);
    SetArmourClass(ARMOUR_PLATE);
    SetProperty("multiples", 1);
    SetVendorType(VT_ARMOUR);
    SetValue(800);
    SetMass(400);
    SetDamagePoints(2000);
    // SetProtection(BLUNT, 26);
    // SetProtection(SLASH, 26);
    // SetProtection(PIERCE, 12);
    // SetProtection(WATER, 5);
    // SetProtection(COLD, 5);
    // SetProtection(HEAT, 5);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 4);
    SetArmourType(A_PANTS);
    SetRestrictLimbs( ({ "left leg", "right leg"}) );
    SetWear("Your legs fit snugly into the greaves.");
}
