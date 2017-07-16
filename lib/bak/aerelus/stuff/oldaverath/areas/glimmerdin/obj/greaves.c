/* Duhoc.1.99 - 8 lb. chain 'pants' */
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

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
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_CHAIN);
    SetMass(320);
    SetValue(350);
    SetDamagePoints(900);
    SetSize(SIZE_SMALL);
}
