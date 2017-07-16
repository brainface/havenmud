#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour", "leather" }) );
    SetAdjectives( ({ "leather", "studded" }) );
    SetShort("a studded leather armour");
    SetLong("This is a good, solidly crafted shirt of leather armour with metal "
    "studs in it for added protection.");
    SetVendorType(VT_ARMOUR);
    SetMass(190);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_REINFORCED);
    SetValue(150);
    SetDamagePoints(2500);
    SetMaterial( ({ "leather", "metal" }) );
    SetWarmth(35);
    SetRepairSkills( ([ 
          "armour smithing" : 1,
          "leather working" : 3 ]) );
    SetRepairDifficulty(11);
    // SetProtection(BLUNT, 10);
    // SetProtection(SLASH, 15);
    // SetProtection(PIERCE,15);
    // SetProtection(HEAT, 2);
    // SetProtection(COLD, 4);
    // SetProtection(SHOCK, 6);
    // SetProtection(WATER, 1);
    // SetProtection(ACID, 1);
    SetArmourType(A_BODY_ARMOUR);
}
