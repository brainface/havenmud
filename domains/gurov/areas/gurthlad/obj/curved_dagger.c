#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
 
 
static void create() {
        item::create();
        SetShort("a curved dagger");
        SetLong("The dagger is long and wickedly curved. It looks like "
        "it would be fairly easy to rip someone's guts out with "
        "this dagger.");
        SetId( ({"dagger"}) );
        SetClass(9);
        SetDamagePoints(500);
        SetMaterial( ({ "metal" }) );
        SetRepairSkills( ([ "weapon smithing" : 1,
                            "metal working" : 1, ]) );
        SetRepairDifficulty(9);
        SetValue(80);
        SetWeaponType("knife");
        SetDamageType(SLASH);
        SetKeyName("dagger");
        SetMass(45);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "curved","long","wickedly"}) );
}
