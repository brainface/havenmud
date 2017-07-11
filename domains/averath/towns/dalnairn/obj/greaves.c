/* Duhoc.1.99 - 8 lb. chain 'pants' */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("chainmail leg greaves");
    SetId( ({ "greaves"}) );
    SetAdjectives( ({ "chainmail", "mail", "chain", "leg", "black" }) );
    SetShort("a pair of black chainmail leg greaves");
    SetLong("The chainmail greaves are of thick, black dwarven chain. "
      "They hang over the legs in a very loose fit to provide ample "
      "room for movement.");
    SetArmourType(A_PANTS);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_CHAIN);
    SetMaterial("metal");
    SetRepairDifficulty(40);
    SetMass(320);
    SetValue(1500);
    SetDamagePoints(1500);
}
