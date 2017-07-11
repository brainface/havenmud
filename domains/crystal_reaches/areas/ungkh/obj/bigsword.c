//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetShort("a huge sword");
        SetLong(
        "This enormous blade looks like it could be used to tear "
        "down whole forests in capable hands. "
        );
        SetId( ({"weapon","sword"}) );
        SetAdjectives("huge");
        SetMaterial("metal");
        SetRepairDifficulty(15);
        SetClass(12);
        SetDamagePoints(1500);
        SetValue(1250);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("huge sword");
        SetMass(550);
        SetVendorType(VT_WEAPON);
        SetHands(2);
    }
    
