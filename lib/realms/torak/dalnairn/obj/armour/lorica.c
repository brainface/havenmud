#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("lorica");
    SetId( ({ "ringmail", "lorica", "armour", "shirt"}) );
    SetAdjectives( ({ "ringmail", "thick", "heavy", "durable", "black"}) );
    SetShort("a ringmail lorica");
    SetLong("This is a thick, heavy shirt of black ringmail.  It was made "
            "in the forges of Dalnairn, and it looks quite durable.");
    SetMass(450);
    SetValue(1000);
    SetMaterial("metal");
    SetRepairDifficulty(30);
    SetArmourClass(ARMOUR_CHAIN);
    SetSize(SIZE_SMALL);
    SetDamagePoints(2000);
    SetArmourType(A_ARMOUR);
}
