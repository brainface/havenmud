#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create () {
    item::create();
    SetKeyName("mace");
    SetId( ({ "spiked mace", "mace" }) );
    SetShort("a spiked mace");
    SetLong("This weapon is made of a long wooden pole with a heavy metal "
    "sphere attached to the end.  There are several nasty looking spikes "
    "protruding from the sphere which would inflict extra damage on an "
    "opponent");
    SetMass(250);
    SetClass(13);
    SetWeaponType("blunt");
    SetDamageType(BLUNT|PIERCE);
    SetValue(300);
    SetVendorType(VT_WEAPON);
    SetMaterial( ({ "wood", "metal" }) );
    SetRepairSkills( ([
    "metal working" : 5,
    "weapon smithing" : 5,
]) );
    SetRepairDifficulty(20);
}
