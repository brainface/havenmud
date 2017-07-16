#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("pike");
    SetId( ({ "long metal pike", "metal pike", "long pike", "pike" }) );
    SetShort("a long metal pike");
    SetLong("This long shaft of dark metal is sharpened to a deadly point at "
    "one end.  Leather straps are wrapped around the middle acting as "
    "hand holds.  It looks like this weapon could be driven with ease "
    "into someone's body by anyone with a good amount of skill in wielding "
    "it.");
    SetMass(130);
    SetValue(120);
    SetVendorType(VT_WEAPON);
    SetClass(12);
    SetWeaponType("pierce");
    SetDamageType(PIERCE);
    SetHands(2);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
    "metal working" : 4,
    "weapon smithing" : 4,
    ]) );
    SetRepairDifficulty(11);
}
