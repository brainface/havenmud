/* Duhoc.1.99 - 8 lb. chain 'pants' */
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("chainmail leg greaves");
    SetId( ({ "greaves"}) );
    SetAdjectives( ({ "chainmail", "mail", "chain", "leg", }) );
    SetShort("a pair of chainmail leg greaves");
    SetLong("The chainmail greaves are of thick, dwarven chain. "
      "They hang over the legs in a very loose fit to provide ample "
      "room for movement.");
    SetArmourType(A_PANTS);
    SetSize(SIZE_SMALL);
    SetMass(320);
    SetValue(350);
    SetDamagePoints(900);
    SetProtection(BLUNT, 20);
    SetProtection(SLASH, 20);
    SetProtection(PIERCE, 20);
    SetProtection(HEAT, 1);
    SetProtection(COLD, 1);
    SetProtection(SHOCK, 0);
    SetProtection(WATER, 0);
    SetProtection(ACID, 3);
}
