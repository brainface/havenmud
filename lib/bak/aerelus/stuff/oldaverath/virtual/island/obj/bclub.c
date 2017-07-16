#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("bone club");
    SetId(({ "club", "bone club" }) );
    SetAdjectives( ({ "large" }) );
    SetShort("a large bone club");
    SetLong("This is a large and extremely heavy club made out of "
            "what appears to be the leg bone of some large humanoid "
            "creature, perhaps an ogre or a troll. It also appears "
            "to have been chewed on quite a bit. ");
    SetMass(500);
    SetValue(50);
    SetVendorType(VT_WEAPON);
    SetClass(12);
    SetDamageType(BLUNT);
    SetWeaponType("blunt");
}
