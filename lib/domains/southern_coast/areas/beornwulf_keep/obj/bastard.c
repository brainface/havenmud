#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("sword");
    SetId( ({ "sword", "bastard sword"}) );
    SetAdjectives( ({ "bastard"}) );
    SetShort("a bastard sword");
    SetLong("The blade of this deadly sword is over 3 feet long, and "
            "has the ability to slash an enemy to pieces.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 16,
          "weapon smithing" : 17,
					]) );
    SetRepairDifficulty(60);
    SetVendorType(VT_WEAPON);
    SetDamagePoints(2500);
    SetClass(20);
    SetMass(400);
    SetValue(350);
    SetHands(2);
    SetWeaponType("slash");
    SetDamageType(SLASH);
}
