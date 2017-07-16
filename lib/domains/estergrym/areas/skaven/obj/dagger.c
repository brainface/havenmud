#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ITEM;

static void create()
{
item::create();
        SetKeyName("dagger");
        SetId( ({ "dagger" }) );
        SetAdjectives(  ({ "rusty" })  );
        SetShort("a rusty dagger");
        SetLong("This old dagger is of dubious quality and utility. "
                "The rusted blade itself is rough, jagged, and heavily stained."
                "The leather grip that once adorned the hilt has rotted away.");
        SetMass(50);
        SetValue(10);
        SetDamagePoints(200);
        SetWeaponType("knife");
        SetDamageType(PIERCE);
        SetClass(5);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ "weapon smithing" : 1 ])  );
        SetRepairDifficulty(5);
}
