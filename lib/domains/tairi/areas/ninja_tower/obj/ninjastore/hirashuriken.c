#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetKeyName("shuriken");
        SetId( ({ "shuriken", "hira shuriken", "hira-shuriken"  }) );
        SetAdjectives(  ({ "steel", "throwing" })  );
        SetShort("a hira shuriken");
        SetLong("This is a small mostly circular cross"
                " piece of metal. The ends have been"
                " filed down and sharpened to provide"
                " a razor blade edge. The center of"
                " this shuriken has a hole that is"
                " used as a point of reference when"
                " holding and throwing this weapon." );
        SetMass(5);
        SetValue(100);
        SetDamagePoints(500);
        SetWeaponType("projectile");
        SetDamageType(SLASH);
        SetClass(15);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
            "weapon smithing" : 2, 
            "metal working" : 2, 
            ])  );
        SetRepairDifficulty(8);
} 
