//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetShort("a lance");
        SetLong(
          "This lance is quite versatile, as it can be used "
        "either for throwing through ranks of attacking enemies "
        "or as a spear or crutch in hard times.");
        SetId( ({"lance","weapon"}) );
        SetClass(8);
        SetDamagePoints(450);
        SetValue(1200);
        SetWeaponType("pierce");
        SetDamageType(PIERCE);
        SetKeyName("lance");
        SetMass(200);
        SetVendorType(VT_WEAPON);
        
        SetMaterial("wood");
        SetRepairDifficulty(10);
    }
