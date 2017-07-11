#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../keryth.h"

static void create() {
        item::create();
        SetShort("a shortsword");
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(9);
        SetLong("The small, metal sword looks almost laughable.");
        SetId( ({"short","sword","shortsword","metal sword"}) );
        SetClass(3);
        SetDamagePoints(140);
        SetValue(0);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("sword");
        SetMass(55);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "short"}) );
}
