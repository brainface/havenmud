//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
  
static void create() {
    item::create();
    SetShort("an iron broadsword");
    SetId( ({ "broadsword", "sword" }) );
    SetAdjectives( ({ "iron" }) );
    SetKeyName("broadsword");
    SetLong(
       "This is a heavy broadsword, used for chopping "
       "holes into the enemy from some distance away. "
       "The hilt is fashioned from heavy iron and "
       "a flawed but still pretty agate pommel stone. "
    );
    SetClass(16);
    SetDamagePoints(1200);
    SetValue(50);
    SetWeaponType("slash");
    SetDamageType(SLASH);
    SetMass(70);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(20);
    SetVendorType(VT_WEAPON);
}