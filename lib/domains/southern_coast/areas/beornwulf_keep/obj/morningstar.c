#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();


    SetKeyName("morning star");
    SetId( ({ "star", "morningstar" }) );
    SetAdjectives( ({ "morning", "iron" }) );
    SetShort("an iron morning star");
    SetLong("This brutally efficient weapon is comprised of a massive "
           "iron sphere hanging from a chain.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "weapon smithing" : 7,
          "metal working" : 7,
					]) );
    SetRepairDifficulty(34);
    SetVendorType(VT_WEAPON);
    SetDamagePoints(900);
    SetClass(10);
    SetMass(110);
    SetValue(500);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
}
