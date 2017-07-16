#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("copper-studded belt");
    SetId( ({ "belt"}) );
    SetAdjectives( ({ "copper", "studded", }) );
    SetShort("a copper-studded belt");
    SetLong("The thick leather belt is augmented with copper studs "
            "to add extra protection.");
    SetArmourType(A_BELT);
    SetMass(20);
    SetValue(80);
    SetDamagePoints(400);
    // SetProtection(BLUNT, 2);
    // SetProtection(SLASH, 4);
    // SetProtection(PIERCE, 3);
    // SetProtection(HEAT, 0);
    // SetProtection(COLD, 0);
    // SetProtection(SHOCK, 0);
    // SetProtection(WATER, 0);
    // SetProtection(ACID, 1);
  SetSize(SIZE_SMALL);
}
