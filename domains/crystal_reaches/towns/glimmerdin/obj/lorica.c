#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("ringmail lorica");
    SetId( ({ "ringmail", "lorica", "armour"}) );
    SetAdjectives( ({ "ringmail", "thick", "heavy", "durable" }) );
    SetShort("a ringmail lorica");
    SetLong("This is a thick, heavy shirt of ringmail.  It was made "
            "in the forges of Glimmerdin, and it looks quite durable.");
    SetMass(450);
    SetValue(400);
    SetMaterial("metal");
    SetRepairDifficulty(30);
    SetArmourClass(ARMOUR_CHAIN);
    SetSize(SIZE_SMALL);
    SetDamagePoints(1200);
    // SetProtection(BLUNT, 15);
    // SetProtection(SLASH, 20);
    // SetProtection(PIERCE, 16);
    // SetProtection(HEAT, 1);
    // SetProtection(COLD, 1);
    // SetProtection(SHOCK, 0);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 3);
    SetArmourType(A_ARMOUR);
}
