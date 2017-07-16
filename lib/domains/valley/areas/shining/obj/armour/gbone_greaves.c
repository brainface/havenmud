#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("leg greaves");
    SetId( ({ "greaves", "leg greaves" }) );
    SetShort("green bone leg greaves");
    SetLong("The set of bone greaves is handcrafted from only the "
            "finest bones. It has almost a mirror-like reflection "
            "to it. It was obviously coated with some sort of "
            "liquid. The greaves cover from the ankle to the hip "
            "of anyone who could wear them. The small carvings in "
            "the bones resemble many seen around the forest. It "
            "appears to be part out a full outfit. ");
    SetMaterial( ({ "natural" }) );
    SetRepairSkills( ([
          "metal working" : 25,
          "armour smithing" : 25,
                                        ]) );
    SetRepairDifficulty(50);
    SetArmourClass(ARMOUR_NATURAL);
    SetSize(SIZE_VERY_SMALL);
    SetProperty("multiples", 1);
    SetVendorType(VT_ARMOUR);
    SetValue(800);
    SetMass(400);
    SetDamagePoints(10000);
    SetProtectionBonus(BLUNT, 50);
    SetProtectionBonus(WATER, 50);
    SetProtectionBonus(COLD, 50);
    SetProtectionBonus(HEAT, 50);
    SetProtectionBonus(SHOCK, 50);
    SetArmourType(A_PANTS);
    SetRestrictLimbs( ({ "left leg", "right leg"}) );
    SetWear("You slip gently into the soft tissued greaves.");
}
