/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>c
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
        item::create();
        SetShort("a slingshot");
        SetMaterial("wood");
        SetRepairSkills( ([
            "wood working" : 2,
            "weapon smithing" : 2,
        		]) );
        SetRepairDifficulty(15);
        SetLong("This is a tiny slingshot made out of a thick stick "
                "and some sort of animal sinew.  While poorly crafted, "
                "it appears that it still be fairly dangerous.");
        SetId( ({"sling", "slingshot"}) );
        SetClass(6);
        SetDamagePoints(1000);
        SetValue(60);
        SetWeaponType("projectile");
        SetDamageType(BLUNT);
        SetKeyName("slingshot");
        SetMass(45);
        SetVendorType(VT_WEAPON);
}
