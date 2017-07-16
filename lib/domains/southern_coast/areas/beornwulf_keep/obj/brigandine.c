#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();

    SetKeyName("brigandine armour");
    SetId( ({ "armour", "brigandine armour" }) );
    SetAdjectives( ({ "brigandine" }) );
    SetShort("brigandine armour");
    SetLong("This suit of armour is made from small metal plates sewn to "
            "a layer of canvas and protected by an outer layer of leather.");
    SetMaterial( ({ "metal" , "leather" }) );
 		SetWarmth(20);
    SetRepairSkills( ([
          "metal working" : 5,
          "leather working" : 5,
          "armour smithing" : 6
					]) );
    SetRepairDifficulty(30);
  	SetArmourClass(ARMOUR_PLATE);
    SetVendorType(VT_ARMOUR);
    SetDamagePoints(1000);
    // SetProtection(BLUNT, 10);
    // SetProtection(SLASH, 11);
    // SetProtection(PIERCE, 10);
    // SetProtection(WATER, 8);
    // SetProtection(COLD, 9);
    // SetProtection(HEAT, 5);
    SetValue(200);
    SetSize(SIZE_LARGE);
    SetMass(300);
    SetArmourType(A_ARMOUR);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
}
