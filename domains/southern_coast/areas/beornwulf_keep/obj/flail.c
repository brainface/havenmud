#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("footman's flail");
    SetId( ({"flail", "footman's flail" }) );
    SetShort("a footman's flail");
    SetLong("This small flail is the standard weapon of the human infantry.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "weapon smithing" : 5,
          "metal working" : 7,
					]) );
    SetRepairDifficulty(30);
    SetVendorType(VT_WEAPON);
    SetDamagePoints(600);
    SetClass(8);
    SetMass(100);
    SetValue(200);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
}
