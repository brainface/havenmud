#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();

    SetKeyName("shimmering sword");
    SetId( ({ "shimmering sword", "sword" }) );
    SetShort("a shimmering sword");
    SetLong("This sword is quite long and made of a strange looking metal. "
    "The blade is very hard and shiny, causing light to refract strangely.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(2500);
    SetClass(18);
    SetMass(250);
    SetValue(1500);
    SetWeaponType("slash");
    SetDamageType(MAGIC|SLASH);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
    "weapon smithing" : 12,
    "metal working" : 12,
]) );
    SetRepairDifficulty(60);
    SetProperty("magic", "The metal of the blade is exuding power at an "
    "enormous rate.");
}
