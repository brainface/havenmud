#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ITEM;

static void create() {
				item::create();
        SetKeyName("stars");
        SetId( ({ "stars", "steel throwing stars"  }) );
        SetAdjectives(  ({ "steel", "throwing" })  );
        SetShort("steel throwing stars");
        SetLong("This is a handful of steel throwing stars, "
                "each of them twisted and jagged in its own "
                "particular way.  They are fairly heavy and "
                "appear to be poisoned as small traces of a purplish "
                "residue cover the weapons." );
        SetMass(45);
        SetValue(200);
        SetDamagePoints(500);
        SetWeaponType("projectile");
        SetDamageType(PIERCE);
        SetClass(10);
        SetPoison(15);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
        		"weapon smithing" : 2, 
            "metal working" : 2, 
            ])  );
        SetRepairDifficulty(8);
}
