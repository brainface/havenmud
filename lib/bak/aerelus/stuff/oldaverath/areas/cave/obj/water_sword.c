
// Water Sword
// Laoise
// May 2001

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
    ::create();
    SetKeyName("water sword");
    SetId( ({ "sword" }) );
    SetAdjectives( ({ "watery", "short" }) );
    SetShort("a watery short sword");
    SetLong(
    "This short sword has a dark blue handle and a light blue blade. "
    "Swirling forms move and twist in the interior of the sword, making "
    "the blade appear to be formed of solidified water. At the base of "
    "the blade a raised sigil in the form of a starfish can be seen. "
    "The hilt has deep grooves in it, which curve around and create "
    "texture, giving the sword a better grip."
    );
    SetWield("The sword of water feels solid yet somehow slippery as "
    "you wield it.");
    SetDamagePoints(500);
    SetClass(10);
    SetDamageType(SLASH);
    SetWeaponType("slash");
    SetHands(1);
    SetVendorType(VT_WEAPON);
    SetValue(110);
}
