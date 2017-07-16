#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a shortsword");
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(9);
        SetLong("A small, standard issue shortsword "
                "looks to be somewhat durable.");
        SetId( ({"short", "shortsword","short"}) );
        SetClass(9);
        SetDamagePoints(440);
        SetValue(80);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("sword");
	SetMass(55);
	SetVendorType(VT_WEAPON);
	SetAdjectives( ({ "short"}) );
}
