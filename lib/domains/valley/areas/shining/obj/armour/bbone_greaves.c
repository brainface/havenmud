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
    SetShort("black bone leg greaves");
    SetLong("This set of bone leg greaves covers both legs from ankle to "
          "thigh. They are made up of very solid bones taken from a grizzly "
          "bear's leg. They have been dipped in a black laquer to greatly "
          "raise the durability. ");
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
