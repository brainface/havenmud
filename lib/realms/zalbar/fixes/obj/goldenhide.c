//coded by Syra 8/97
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("hide");
    SetId( ({ "pelt","hide" }) );
    SetAdjectives( ({ "soft","golden","hind's" }) );
    SetShort("the golden hind's pelt");
    SetLong("The soft golden pelt looks valuable and very warm."
            " It has been taken from the once mighty golden"
            " hind, Tarandus.");
    SetVendorType(VT_ARMOUR);
    SetMass(400);
    SetValue(280);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_NATURAL);
    SetDamagePoints(1000);
    SetMaterial( ({ "leather" }) );
    SetWarmth(40);
    SetRepairDifficulty(60);
    SetProtectionBonus(BLUNT, 15);
    // SetProtection(SLASH, 7);
    // SetProtection(PIERCE, 7);
    // SetProtection(HEAT, 3);
    SetProtectionBonus(COLD, 10);
    SetProtectionBonus(SHOCK, 25);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 3);
    SetArmourType(A_ARMOUR);
    SetWear("You feel protected as you wear the golden Hind's pelt.");
    SetRepairSkills( ([ 
                 "leather working" : 6,
                 "armour smithing" : 6,
                 ]) );
}

/* Approved by Amelia on Sun Sep 14 19:50:52 1997. */
