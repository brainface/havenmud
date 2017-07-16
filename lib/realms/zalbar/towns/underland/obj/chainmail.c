#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("chainmail");
    SetId( ({ "chainmail" }) );
    SetAdjectives( ({ "dwarven", "sturdy", "suit of" }) );
    SetShort("a suit of sturdy dwarven chainmail");
    SetLong("This suit of dwarven chainmail is composed of a thick "
      "and extremely durable steel mesh.  It has tremendous resilience "
      "because it was forged by a great dwarven smith specifically "
      "for the dwarven body shape.");
    SetMass(650);
    SetProperty("multiples", 1);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(40);
    SetValue(450);
    SetArmourClass(ARMOUR_CHAIN);
    SetDamagePoints(1500);
    // SetProtection(BLUNT, 20);
    // SetProtection(SLASH, 20);
    // SetProtection(PIERCE, 15);
    SetArmourType(A_BODY_ARMOUR);
    SetSize(SIZE_SMALL);
}

