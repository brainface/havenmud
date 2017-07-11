#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour", "leather", }) );
    SetAdjectives( ({ "leather", "ragged" }) );
    SetShort("a ragged leather armour");
    SetLong("This is a ragged, torn, stained suit of leather armour.");
    SetVendorType(VT_ARMOUR);
    SetMass(175);
    SetSize(SIZE_LARGE);
    SetValue(65);
    SetArmourClass(ARMOUR_LEATHER);
    SetDamagePoints(300);
    SetMaterial( ({ "leather" }) );
    SetWarmth(20);
    SetRepairSkills( ([ "leather working" : 1 ]) );
    SetRepairDifficulty(6);
    // SetProtection(BLUNT, 6);
    // SetProtection(SLASH, 10);
    // SetProtection(PIERCE, 9);
    // SetProtection(HEAT, 1);
    // SetProtection(COLD, 2);
    // SetProtection(SHOCK, 5);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 1);
    SetArmourType(A_ARMOUR);
  }
