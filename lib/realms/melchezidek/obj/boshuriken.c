#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetKeyName("shuriken");
        SetId( ({ "shuriken", "bo shuriken", "bo-shuriken"  }) );
        SetAdjectives(  ({ "steel", "throwing" })  );
        SetShort("a bo shuriken");
        SetLong("This small steel rod is known to be"
                " very deadly when used by the right person."
                " One tip has been sharpened to allow for"
                " maximum penetration when thrown. It is"
                " about four inches long and weighs only"
                " a few ounces making it extremely easy"
                " to conceal." );
        SetMass(5);
        SetValue(200);
        SetDamagePoints(500);
        SetWeaponType("projectile");
        SetDamageType(PIERCE);
        SetClass(13);
        SetPoison(5);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
            "weapon smithing" : 2, 
            "metal working" : 2, 
            ])  );
        SetRepairDifficulty(8);
}
